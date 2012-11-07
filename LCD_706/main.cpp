//
//  main.cpp
//  LCD_706
//
//  Created by Charles R. Hardnett on 10/23/12.
//  Copyright (c) 2012 Charles R. Hardnett. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
/*
 The 7-segment display is drawn using functions based on this model:
 
  ---     <---- cap segment
 |   |
 |   |    <---- top segments
  ---     <---- mid segment
 |   |
 |   |    <---- bot segments
  ---     <---- foot segment
 
*/

void cap(int size, char digit);
void top(int size, char digit);
void mid(int size, char digit);
void bot(int size, char digit);
void foot(int size, char digit);

// draw a horizontal segment
void horizontal(int size);
// draw a space
void horizontalSpace(int size);
// draw a vertical segment
void vertical(int size);
// draw parallel vertical segments
void vertical2bar(int size);


int main(int argc, const char * argv[])
{
    int size;
    string numbers;
    
    // processes each line of input, one line at a time
    while (cin >> size >> numbers) {
        
        //  special condition: end of program
        if (size == 0 && numbers == "0")
            return 0;

        // error condition: values out of range
        if (size > 10 || size <= 0 || numbers[0] == '-' || numbers.length() > 8)
            continue;

        // handles the cap segment for all digits
        for (int count = 0; count < numbers.size(); count++) {
            cap(size, numbers[count]);
            horizontalSpace(1);
        }
        
        cout << endl;
        
        // handles the top segments for all digits
        for (int rows = 1; rows <= size; rows++) {
            for (int count = 0; count < numbers.size(); count++) {
                top(size, numbers[count]);
                horizontalSpace(1);
            }
            cout << endl;
        }

        // hangles the mid segment for all digits
        for (int count = 0; count < numbers.size(); count++) {
            mid(size, numbers[count]);
           horizontalSpace(1);
        }
        
        cout << endl;
        
        // handles the bottom segments for all digits
        for (int rows = 1; rows <= size; rows++) {
            for (int count = 0; count < numbers.size(); count++) {
                bot(size, numbers[count]);
                horizontalSpace(1);
            }
        
            cout << endl;
        }
        
        // handles the foot segments for all digits
        for (int count = 0; count < numbers.size(); count++) {
            foot(size, numbers[count]);
            horizontalSpace(1);
        }

        cout << endl << endl;
    }

    return 0;
}

/*
 The 7-segment display is drawn using functions based on this model:
 
  ---     <---- cap segment
 |   |
 |   |    <---- top segments
  ---     <---- mid segment
 |   |
 |   |    <---- bot segments
  ---     <---- foot segment
 
 */


void cap(int size, char digit) {
    switch (digit) {
        case '1':
        case '4':
            horizontalSpace(size+2);
            break;
        case '0':
        case '2':
        case '3':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            horizontalSpace(1);
            horizontal(size);
            horizontalSpace(1);
            break;
        default:
            cout << "Unknown char(cap): " << digit << endl;
    }
}

void top(int size, char digit) {
        switch (digit) {
            case '1':
            case '2':
            case '3':
            case '7':
                horizontalSpace(size+1);
                vertical(1);
                break;
            case '0':
            case '4':
            case '8':
            case '9':
                vertical2bar(size);
                break;
            case '5':
            case '6':
                vertical(1);
                horizontalSpace(size+1);
                break;
            default:
                cout << "Unknown char(top): " << digit << endl;
        }
}

void mid(int size, char digit) {
     switch (digit) {
        case '0':
        case '1':
        case '7':
            horizontalSpace(size+2);
            break;
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '8':
        case '9':
             horizontalSpace(1);
             horizontal(size);
             horizontalSpace(1);
            break;
        default:
            cout << "Unknown char(mid): " << digit << endl;
    }
 }


void bot(int size, char digit) {

    switch (digit) {
        case '1':
        case '3':
        case '4':
        case '7':
        case '9':
        case '5':
            horizontalSpace(size+1);
            vertical(1);
            break;
        case '0':
        case '6':
        case '8':
            vertical2bar(size);
            break;
        case '2':
            vertical(1);
            horizontalSpace(size+1);
            break;
        default:
            cout << "Unknown char(bot): " << digit << endl;

    }    
}


void foot(int size, char digit) {
    switch (digit) {
        case '1':
        case '4':
        case '7':
            horizontalSpace(size+2);
            break;
        case '0':
        case '2':
        case '3':
        case '5':
        case '6':
        case '8':
        case '9':
            horizontalSpace(1);
            horizontal(size);
            horizontalSpace(1);
            break;
        default:
            cout << "Unknown char(foot): " << digit << endl;
    }
}

// draw a horizontal segment
void horizontal(int size) {
     for (int s = 1; s <= size; s++)
         cout << '-';
    
}

// draw a space
void horizontalSpace(int size) {
     for (int s = 1; s <= size; s++)
         cout << ' ';
    
}

// draw a vertical segment
void vertical(int size) {
      for (int s = 1; s <= size; s++)
         cout << '|';
}

// draw parallel vertical segments
void vertical2bar(int size) {
    vertical(1);
    for (int s = 1; s <= size; s++)
        cout << ' ';
    vertical(1);
}
