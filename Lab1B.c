/*
Kocis, Alan
Lab 1B
2/27/23

Program that inputs three non-zero positive integer sidelenths and determines whether the triangle is equilateral,
scalene, or isosceles as well as the area of the triangle. Program error checks for negative or 0 lengths as well as
cases where the sum of any two sides are less than the remaining side, and will not perform calculations if there
is an error with the side lengths. The program outputs the entered side lengths, the type of the triangle as well as its area, 
then asks the user if they would like to rerun the program.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	char userContinue;
	int side1, side2, side3;
	int error = 0;
	double s;
	double area;

	do {
		userContinue = 'z';		/* set to random char so that a loop later down works  */
		printf("Enter three positive side lengths separated by spaces: ");
		scanf("%d%d%d", &side1, &side2, &side3);

		printf("\nSide 1: %d\nSide 2: %d\nSide 3: %d\n", side1, side2, side3);

		if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
			printf("Error: one or more side lengths are less than or equal to 0.\n");
			error = 1;
		}
		else if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2) {
			printf("Error: The sum of any two sides must be greater than the remaining side.\n");
			error = 1;
		}

		if (error == 0) {
			printf("Triangle type: ");

			/* determining if triangle is equilateral */
			if (side1 == side2 && side2 == side3) {
				printf("Equillateral\n");
			}
			/* determining if triangle is scalene */
			else if (side1 != side2 && side1 != side3 && side2 != side3) {
				printf("Scalene\n");
			}
			/* else triangle will be isosceles */
			else {
				printf("Isosceles\n");
			}

			/*Finding area */
			s = (side1 + side2 + side3) / 2.0;
			area = sqrt((s * (s - side1) * (s - side2) * (s - side3)));
			printf("Area: %.2f\n\n", area);

		}

		/* loop makes sure that input is y Y n or N. This is why I set userContinue to z earlier */
		while (userContinue != 'y' && userContinue != 'Y' && userContinue != 'n' && userContinue != 'N') {
			printf("Run program again? Enter y or n: ");
			scanf(" %c", &userContinue);
		}
	} while (userContinue == 'y' || userContinue == 'Y');

	return 0;
}


/*
Outputs:

Enter three positive side lengths separated by spaces: 0 1 2

Side 1: 0
Side 2: 1
Side 3: 2
Error: one or more side lengths are less than or equal to 0.
Run program again? Enter y or n: n

C:\Users\alank\source\repos\CS_114_Lab1B\x64\Debug\CS_114_Lab1B.exe (process 25628) exited with code 0.
Press any key to close this window . . .


---

Enter three positive side lengths separated by spaces: 1 -4 3

Side 1: 1
Side 2: -4
Side 3: 3
Error: one or more side lengths are less than or equal to 0.
Run program again? Enter y or n: n

C:\Users\alank\source\repos\CS_114_Lab1B\x64\Debug\CS_114_Lab1B.exe (process 10100) exited with code 0.
Press any key to close this window . . .

---

Enter three positive side lengths separated by spaces: 8 9 10000

Side 1: 8
Side 2: 9
Side 3: 10000
Error: The sum of any two sides must be greater than the remaining side.
Run program again? Enter y or n: n

C:\Users\alank\source\repos\CS_114_Lab1B\x64\Debug\CS_114_Lab1B.exe (process 1224) exited with code 0.
Press any key to close this window . . .

---

Enter three positive side lengths separated by spaces: 10 10 10

Side 1: 10
Side 2: 10
Side 3: 10
Triangle type: Equillateral
Area: 43.30

Run program again? Enter y or n: y
Enter three positive side lengths separated by spaces: 3 4 5

Side 1: 3
Side 2: 4
Side 3: 5
Triangle type: Scalene
Area: 6.00

Run program again? Enter y or n: y
Enter three positive side lengths separated by spaces: 5 5 9

Side 1: 5
Side 2: 5
Side 3: 9
Triangle type: Isosceles
Area: 9.81

Run program again? Enter y or n: Z
Run program again? Enter y or n: n

C:\Users\alank\source\repos\CS_114_Lab1B\x64\Debug\CS_114_Lab1B.exe (process 15212) exited with code 0.
Press any key to close this window . . .

---

*/