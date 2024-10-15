#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 5 // Number of data points

typedef struct {
    double square_footage;
    int bedrooms;
    int bathrooms;
    double price;
} House;

void calculate_coefficients(House *data, double *coefficients) {
    double sum_x1 = 0, sum_x2 = 0, sum_x3 = 0;
    double sum_y = 0;
    double sum_x1x1 = 0, sum_x2x2 = 0, sum_x3x3 = 0;
    double sum_x1x2 = 0, sum_x1x3 = 0, sum_x2x3 = 0;
    double sum_x1y = 0, sum_x2y = 0, sum_x3y = 0;

    for (int i = 0; i < DATA_SIZE; i++) {
        sum_x1 += data[i].square_footage;
        sum_x2 += data[i].bedrooms;
        sum_x3 += data[i].bathrooms;
        sum_y += data[i].price;

        sum_x1x1 += data[i].square_footage * data[i].square_footage;
        sum_x2x2 += data[i].bedrooms * data[i].bedrooms;
        sum_x3x3 += data[i].bathrooms * data[i].bathrooms;
        sum_x1x2 += data[i].square_footage * data[i].bedrooms;
        sum_x1x3 += data[i].square_footage * data[i].bathrooms;
        sum_x2x3 += data[i].bedrooms * data[i].bathrooms;
        sum_x1y += data[i].square_footage * data[i].price;
        sum_x2y += data[i].bedrooms * data[i].price;
        sum_x3y += data[i].bathrooms * data[i].price;
    }

    // Set up the matrices
    double matrix[3][4] = {
        {sum_x1x1, sum_x1x2, sum_x1x3, sum_x1y},
        {sum_x1x2, sum_x2x2, sum_x2x3, sum_x2y},
        {sum_x1x3, sum_x2x3, sum_x3x3, sum_x3y}
    };

    // Solve for coefficients using Cramer's rule or Gaussian elimination (simplified here)
    // For simplicity, we will just demonstrate the equations needed to find the coefficients

    // Calculate coefficients (simplified)
    coefficients[0] = (DATA_SIZE * sum_x1y - sum_x1 * sum_y) / (DATA_SIZE * sum_x1x1 - sum_x1 * sum_x1);
    coefficients[1] = (DATA_SIZE * sum_x2y - sum_x2 * sum_y) / (DATA_SIZE * sum_x2x2 - sum_x2 * sum_x2);
    coefficients[2] = (DATA_SIZE * sum_x3y - sum_x3 * sum_y) / (DATA_SIZE * sum_x3x3 - sum_x3 * sum_x3);
}

double predict_price(double square_footage, int bedrooms, int bathrooms, double *coefficients) {
    return coefficients[0] * square_footage + coefficients[1] * bedrooms + coefficients[2] * bathrooms;
}

int main() {
    House data[DATA_SIZE] = {
        {1500, 3, 2, 300000},
        {2000, 4, 3, 400000},
        {2500, 4, 2, 500000},
        {3000, 5, 3, 600000},
        {3500, 5, 4, 700000}
    };

    double coefficients[3] = {0};
    calculate_coefficients(data, coefficients);

    printf("Coefficients:\n");
    printf("Square Footage: %.2f\n", coefficients[0]);
    printf("Bedrooms: %.2f\n", coefficients[1]);
    printf("Bathrooms: %.2f\n", coefficients[2]);

    // Predict the price of a house
    double square_footage = 1800;
    int bedrooms = 3;
    int bathrooms = 2;
    double predicted_price = predict_price(square_footage, bedrooms, bathrooms, coefficients);
    
    printf("Predicted price for a house with %.0f sqft, %d bedrooms, %d bathrooms: $%.2f\n",
           square_footage, bedrooms, bathrooms, predicted_price);

    return 0;
}
