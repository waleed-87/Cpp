//#include <iostream>
//using namespace std;
//
//int main() {
//    double totalCalories, fatGrams, caloriesFromFat, fatPercentage;
//
//    cout << "Enter the total number of calories: ";
//    cin >> totalCalories;
//    cout << "Enter the number of fat grams: ";
//    cin >> fatGrams;
//
//
//    if (totalCalories < 0 || fatGrams < 0) {
//        cout << "Error: Calories and fat grams cannot be less than 0." << endl;
//    }
//    else {
//
////        caloriesFromFat = fatGrams * 9;
////
////
////        if (caloriesFromFat > totalCalories) {
////            cout << "Error: Invalid input. Calories from fat (" << caloriesFromFat
////                << ") cannot be greater than total calories (" << totalCalories << ")." << endl;
////            cout << "Please check if fat grams or total calories were entered incorrectly." << endl;
////        }
////        else {
////            
////            if (totalCalories > 0) {
////                fatPercentage = (caloriesFromFat / totalCalories) * 100;
////
////                cout << "Percentage of calories from fat: " << fatPercentage << "%" << endl;
////
////                
////                if (fatPercentage < 30) {
////                    cout << "This food is low in fat!" << endl;
////                }
////            }
////            else {
////                cout << "Total calories are 0, percentage cannot be calculated." << endl;
////            }
////        }
////    }
////
////    return 0;
////}