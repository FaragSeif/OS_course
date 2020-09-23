#include<stdio.h> 

void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 


void sortArrival(int mat[][6], int num) 
{ 
	for(int i=0; i<num; i++) 
	{ 
		for(int j=0; j<num-i-1; j++) 
		{ 
			if(mat[j][2] > mat[j+1][2]) 
			{ 
				for(int k=0; k<5; k++) 
				{ 
					swap(&mat[j][k], &mat[j+1][k]); 
				} 
			} 
		} 
	} 
} 


void findWT(int mat[][6], int n) 
{ 
	int service_time[n]; 
	service_time[0] = 0; 
	mat[0][3] = 0; 

	for (int i = 1; i < n ; i++) 
	{ 
		// Add burst time of previous processes 
		service_time[i] = service_time[i-1] + mat[i-1][1]; 

		// Find waiting time for current process = 
		// sum - at[i] 
		mat[i][3] = service_time[i] - mat[i][2]; 

		// If waiting time for a process is in negative 
		// that means it is already in the ready queue 
		// before CPU becomes idle so its waiting time is 0 
		if (mat[i][3] < 0) 
			mat[i][3] = 0; 
	} 
} 

void findTAT(int mat[][6], int n) 
{ 
	for (int i = 0; i < n ; i++) 
		mat[i][4] = mat[i][1] + mat[i][3]; 
} 


// Function to calculate average waiting and turn-around 
// times. 
void findAWT(int mat[][6], int n) 
{ 
	// Function to find waiting time of all mat 
	findWT(mat, n); 

	// Function to find turn around time for all mat 
	findTAT(mat, n); 

	// Display mat along with all details 
	printf("PID\t\t BT\t\t AT\t\t WT\t\t TAT\t\tCT\n"); 
	int total_wt = 0, total_tat = 0; 
	for (int i = 0 ; i < n ; i++) 
	{ 
		total_wt = total_wt + mat[i][3]; 
		total_tat = total_tat + mat[i][4]; 
		int compl_time = mat[i][4] + mat[i][2]; 
		printf(  "%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t%d\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4], compl_time); 
	} 

	printf(  "Average waiting time = %f\n", (float)total_wt / (float)n); 
	printf(  "Average turn around time = %f\n",(float)total_tat / (float)n); 
} 


int main() 
{ 

		int num, temp; 
	
	printf("Enter number of Process: "); 
	scanf("%d", &num); 
	int mat[num][6];
	
	printf("...Enter the process ID...\n"); 
	for(int i=0; i<num; i++) 
	{ 
		printf("...Process %d...\n", i+1); 
		printf("Enter Process Id: "); 
		scanf("%d", &mat[i][0]); 
		printf("Enter Arrival Time: "); 
		scanf("%d", &mat[i][2]); 
		printf("Enter Burst Time: "); 
		scanf("%d", &mat[i][1]); 
	} 
	sortArrival(mat,num);
	findAWT(mat, num); 

	return 0; 
} 

