import pandas as pd
import numpy as np
from scipy.spatial import KDTree
from sklearn.preprocessing import QuantileTransformer
import query  # type: ignore


# Initiate test fluid model
fluid_model_test = query.CTestFluidModel(101325.0,300.0,1.13)

# Example calculation, computing the density based on pressure and temperature
fluid_model_test.SetTDState_PT(2e5, 400)
print(fluid_model_test.GetDensity())

# Custom function to compute density based on pressure and temperature.
# This is just a demonstrator! Don't expect accurate predictions from this 
# function.

# Define a function to interpolate using KDTree
def kdtree_interpolate(query_points, kdtree, data_points, values, k=3):
    interpolated_values = []
    
    distances, indices = kdtree.query(query_points, k=k)
    weights = 1 / distances
    weights /= np.sum(weights)
    interpolated_value = np.dot(weights, values[indices])
    interpolated_values.append(interpolated_value)
    return np.array(interpolated_values)


def Interpolate(Prog_var,Enth_Total,Mix_frac):
    training_data_path = 'MethaneFlameletData_LUT.csv'
    training_data = pd.read_csv(training_data_path)
    query_vars = ['ProgressVariable', 'EnthalpyTot', 'MixtureFraction']
    output_vars = ['Temperature', 'MolarWeightMix', 'DiffusionCoefficient', 'Conductivity', 'ViscosityDyn']
    values=np.array([Prog_var,Enth_Total,Mix_frac])
    # Extract query variables and output variables from training data
    train_queries = training_data[query_vars].values
    train_outputs = training_data[output_vars].values

    quantile_transformer = QuantileTransformer(output_distribution='uniform')
    train_queries_scaled = quantile_transformer.fit_transform(train_queries)
    kdtree = KDTree(train_queries_scaled)
    
    # Apply the KDTree-based interpolator to the validation data
    k = 3
    kdtree_interpolated_values = kdtree_interpolate(values, kdtree, train_queries, train_outputs, k=k)
    return int(kdtree_interpolated_values[0][2])

# Goal: pass the customPTfunction to the fluid_model_test to compute the density.

result=fluid_model_test.SetTDState_Custom(101325,300, Interpolate)
print("result: %.3e" % result)