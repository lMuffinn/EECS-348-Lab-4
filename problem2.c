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
float convert_tempurature(float temp, char initial, char target){
    //Convert the tempurature from the initial temp to the target temp
    switch (initial){
        case 'f':
            if (target == 'c') return fahrenheit_to_celsius(temp);
            if (target == 'k') return fahrenheit_to_kelvin(temp);
            break;
        case 'c':
            if (target == 'f') return celsius_to_fahrenheit(temp);
            if (target == 'k') return celcius_to_kelvin(temp);
            break;
        case 'k':
            if (target == 'f') return kelvin_to_fahrenheit(temp);
            if (target == 'c') return kelvin_to_celsius(temp);
            break;
        default:
            return temp;
            break;
    }
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
    if (scale == 'c' && celcius_to_kelvin(temp) < 0){
        return 0;
    }
    else if (scale == 'f' && fahrenheit_to_kelvin(temp) < 0){
        return 0;
    }
    else if (scale == 'k' && temp < 0){
        return 0;
    }
    return 1;
}
//Categorizing The Tempurature
void catagorize_tempurature(float celsius){
    //Put the tempurature into a catagory and output an advisory message
    if (celsius < 0) printf("\nIt's freezing, stay indoors!");
    else if (0 <= celsius && celsius < 10) printf("\nIt's cold, wear a jacket!");
    else if (10 <= celsius && celsius < 25) printf("\nIt's comfortable, go touch some grass!");
    else if (25 <= celsius && celsius < 35) printf("\nIt's hot, wear sunscreen!");
    else printf("\nExtreme heat, make sure to drink water!");
}
//Main Function
int main(){
    //Run the program
    //First we get the inputs from the user
    float temp;
    char scale;
    char target;
    while(1){
        temp = get_temp();
        if (fahrenheit_to_kelvin(temp) < 0){
            printf("\nThat tempurature is impossible");
            continue;
        }
        scale = get_scale();
        if (!valid_temp(temp,scale)){
            printf("\nThat tempurature is impossible");
            continue;
        }
        target = get_target(scale);
        break;
    }
    //Then we convert them into the proper scale
    float contemp = convert_tempurature(temp,scale,target);
    switch (target)
    {
        case 'f':
            printf("\nYour temp: %f degrees fahrenheit", contemp);
            break;
        case 'c':
            printf("\nYour temp: %f degrees celsius", contemp);
            break;
        case 'k':
            printf("\nYour temp: %f degrees kelvin", contemp);
            break;
        default:
            break;
    }
    //Then we output an advisory message based on the tempurature
    catagorize_tempurature(convert_tempurature(temp,scale,'c'));
    //Finally, we give the user an option to exit
    char exit;
    printf("\n\nPress any button to exit: ");
    scanf(" %c",exit);
}