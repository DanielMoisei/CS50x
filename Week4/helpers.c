#include "helpers.h"
#include <math.h>

void switchPixels(RGBTRIPLE *pixelA, RGBTRIPLE *pixelB);
int checkValue(int value);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over the entire image, line by line, left to right
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            
            // Store the pixel inside the function
            RGBTRIPLE pixel = image[i][j];
            
            // Change the pixel's RGB values to be equal to the average of all 3, turning it into gray
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over the entire image, line by line, left to right
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            
            // Store the pixel inside the function
            RGBTRIPLE pixel = image[i][j];
            
            // Store the individual RGB values of the pixel
            int originalRed = pixel.rgbtRed;
            int originalGreen = pixel.rgbtGreen;
            int originalBlue = pixel.rgbtBlue;
            
            // Change the red value of the pixel using the sepia formula
            image[i][j].rgbtRed = checkValue(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));

            // Change the green value of the pixel using the sepia formula
            image[i][j].rgbtGreen = checkValue(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));

            // Change the blue value of the pixel using the sepia formula
            image[i][j].rgbtBlue = checkValue(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width / 2; j++) {
            switchPixels(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Function to cap the value of sepia filtered pixels' RGB values to 255
int checkValue(int value) {
    if(value > 255) {
        return 255;
    } else {
        return value;
    }
}

// Function to swap around pixels by using a temporary variable
void switchPixels(RGBTRIPLE *pixelA, RGBTRIPLE *pixelB) {
    RGBTRIPLE tempPixel = *pixelA;
    *pixelA = *pixelB;
    *pixelB = tempPixel;
}