/*
Tempurature Conversion
Purpose: Allow the user to convert tempuratures and give them valid info based on that tempurature
Date Created: 10-2-2024
Author: Matthew Eagleman
*/
//Headers
#include <stdio.h>
#include <stdlib.h>
//Converting Tempurature
float celsius_to_fahrenheit(float celsius){
    //Return the celsius value converted into fahrenheit
    return (celsius * 9/5) + 32;
}
float fahrenheit_to_celsius(float fahrenheit){
    //Return the fahrenheit value converted into celsius
    return (fahrenheit-32) * 5/9;
}
float celcius_to_kelvin(float celsius){
    //Return the celsius value converted into kelvin
    return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin){
    //Return the kelvin value converted into celsius
    return kelvin - 273.15;
}
float fahrenheit_to_kelvin(float fahrenheit){
    //Return the fahrenheit value converted into kelvin
    return celcius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
float kelvin_to_fahrenheit(float kelvin){
    //Return the kelvin value converted into fahrenheit
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}
//Obtaining Inputs
float get_temp(){
    //Obtain a tempurature from the user
    float temp;
    printf("\nInput temperature: ");
    scanf(" %f", &temp);
    return temp;
}
float get_scale(){
    //Obtain a tempurature scale from the user
    char scale;
    while(1){
        printf("\nInput the temperature scale you'd like to use:\n c) celsius\n f) fahrenheit\n k) kelvin\nYour choice: ");
        scanf(" %c", &scale);
        if (scale == 'c' || scale == 'f' || scale == 'k'){
            break;
        }
        printf("\nInvalid choice, please input c, f, or k");
    }
    return scale;
}
float get_target(char scale){
    //Obtain a target tempurature scale from the user
    char target;
    while(1){
        printf("\nInput your target scale:\n c) celsius\n f) fahrenheit\n k) kelvin\nYour choice: ");
        scanf(" %c", &target);
        if (scale == target){
            printf("\nInvalid choice, %c and %c are the same", scale, target);
            continue;
        }
        if (target == 'c' || target == 'f' || target == 'k'){
            break;
        }
        printf("\nInvalid choice, please input c, f, or k");
    }
    return target;
}
int valid_temp(float temp, char scale){
    //Return a boolean value of whether or not the tempurature can exist in the given tempurature scale
}
//Main Function
int main(){
    //Run the program
    float temp;
    char scale;
    char target;
    while(1){
        temp = get_temp();
        if (fahrenheit_to_kelvin(temp) < 0){
            printf("That tempurature is impossible");
            continue;
        }
        scale = get_scale();
        if (!valid_temp(temp,scale)){
            printf("That tempurature is impossible");
            continue;
        }
        target = get_target(scale);
    }
}