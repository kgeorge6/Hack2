/*
	Air Distance
	Kyle George
	1-14-2020
*/

#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884197169 //Defined for the sake of this problem to 43 digits

// Equation given by Hack document. d=arccos(sin(lat1)sin(lat2) + cos(lat1)cos(lat2)cos(delta)) * R
double calculateAirDistance(double lat1, double lat2, double long1, double long2, double R) {
	double delta = long2-long1; //Difference in longitude
	
	double radScale = PI/180; //Used to convert degrees into radians.
	
	if(delta < 0) {
		delta *=-1;
	}
	
	double sinComponent = sin(lat1 * radScale) * sin(lat2 * radScale);
	double cosComponent = cos(lat1 * radScale) * cos(lat2 * radScale) * cos(delta * radScale);
	double distance = acos(sinComponent + cosComponent) * R;
	
	return distance;
}

int main(void) {
	// Necessary Variables
	double oLat = 0;	//Origin Latitude
	double oLong = 0;	//Origin Longitude
	double dLat = 0;	//Destination Latitude
	double dLong = 0;	//Destination Longitude
	double r = 6371;	//Radius of sphere (in this case the earth)
	
	//Gather input from user
	printf("Origin Latitude: ");
	scanf("%lf", &oLat);
	printf("Origin Longitude: ");
	scanf("%lf", &oLong);
	printf("Destination Latitude: ");
	scanf("%lf", &dLat);
	printf("Destination Longitude: ");
	scanf("%lf", &dLong);
	
	//Run calculation based on input.
	double value = calculateAirDistance(oLat, dLat, oLong, dLong, r);
	
	//Display output to user
	printf("\nLocation Distance\n========================\n");
	printf("Origin:\t\t(%.6f,%.6f)\n",oLat,oLong);
	printf("Destination:\t(%.6f,%.6f)\n",dLat,dLong);
	printf("Air distance is %.6f kms.", value);
	
	return 0;
}

/*
	Tested Data Sets
	Origin		(41.948300, -87.655600)
	Destination (40.820600, -96.705600)
	Expected Output = 764.990931
	Output = 764.990931
	
	Origin		(83.9921, 61.3422)
	Destination	(31.9821, -65.2102)
	Expected Output = 6862.28936
	Output = 6862.289361
	
	Origin		(23.0122, -89.9221)
	Destination (-59.4320, 165.2341)
	Expected Output = 13027.87820
	Output = 13027.878204
	
	Origin		(0.1532, 15.2230)
	Destination (-88.2504, -61.1301)
	Expected Output = 9978.67682
	Output = 9978.676821
	
	Expected values found from the following online calculater 
	that agreed with the provided example in the Hack material:
	https://gps-coordinates.org/distance-between-coordinates.php
*/