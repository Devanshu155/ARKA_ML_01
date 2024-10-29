import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt

# Sample dataset
data = {
    'Square_Footage': [1500, 1600, 1700, 1800, 2000, 2500, 3000, 3500, 4000],
    'Bedrooms': [3, 3, 3, 4, 4, 5, 4, 5, 6],
    'Bathrooms': [2, 2, 2, 3, 3, 4, 3, 4, 4],
    'Price': [300000, 320000, 350000, 370000, 400000, 450000, 500000, 600000, 650000]
}

df = pd.DataFrame(data)

# Prepare the data
X = df[['Square_Footage', 'Bedrooms', 'Bathrooms']]
y = df['Price']

# Split the data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create and train the model
model = LinearRegression()
model.fit(X_train, y_train)

# Make predictions
y_pred = model.predict(X_test)

# Evaluate the model
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print("Mean Squared Error:", mse)
print("R² Score:", r2)

# Visualize the results
plt.scatter(y_test, y_pred)
plt.xlabel('Actual Prices')
plt.ylabel('Predicted Prices')
plt.title('Actual vs Predicted Prices')
plt.plot([min(y_test), max(y_test)], [min(y_test), max(y_test)], color='red')  # diagonal line
plt.show()
why this code is not running in VS CODE





