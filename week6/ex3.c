#include<stdio.h> 
#include<stdbool.h>

void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

void sortArrival(int num, int mat[][6]) 
{ 
	for(int i=0; i<num; i++) 
	{ 
		for(int j=0; j<num-i-1; j++) 
		{ 
			if(mat[j][1] > mat[j+1][1]) 
			{ 
				for(int k=0; k<5; k++) 
				{ 
					swap(&mat[j][k], &mat[j+1][k]); 
				} 
			} 
		} 
	} 
} 

// Function to find the waiting time for all 
// processes
void findWTRR(int mat[][6], int n, int quantum) 
{ 
	// Make a copy of burst times to store remaining 
	// burst times. 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = mat[i][1]; 

	int t = 0; // Current time 

	// Keep traversing mat in round robin manner 
	// until all of them are not done. 
	while (1) 
	{ 
		bool done = true; 

		// Traverse all mat one by one repeatedly 
		for (int i = 0 ; i < n; i++) 
		{ 
			// If burst time of a process is greater than 0 
			// then only need to process further 
			if (rem_bt[i] > 0) 
			{ 
				done = false; // There is a pending process 

				if (rem_bt[i] > quantum) 
				{ 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t += quantum; 

					// Decrease the burst_time of current process 
					// by quantum 
					rem_bt[i] -= quantum; 
				} 

				// If burst time is smaller than or equal to 
				// quantum. Last cycle for this process 
				else
				{ 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t = t + rem_bt[i]; 

					// Waiting time is current time minus time 
					// used by this process 
					mat[i][3] = t - mat[i][1]; 

					// As the process gets fully executed 
					// make its remaining burst time = 0 
					rem_bt[i] = 0; 
				} 
			} 
		} 

		// If all mat are done 
		if (done == true) 
		break; 
	} 
} 


void findTAT(int mat[][6], int n) 
{ 
	for (int i = 0; i < n ; i++) 
		mat[i][4] = mat[i][1] + mat[i][3]; 
} 

// Function to calculate average time 
void findavgTime(int mat[][6], int n,	int quantum) 
{ 
	int total_wt = 0, total_tat = 0; 

	findWTRR(mat, n, quantum); 
	findTAT(mat, n); 

	printf("PID\t\t BT\t\t AT\t\t WT\t\t TAT\t\t CT\n"); 

	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + mat[i][3]; 
		total_tat = total_tat + mat[i][4]; 
		int compl_time = mat[i][4] + mat[i][2]; 
		printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",  mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4], compl_time); 
	} 

	printf("Average waiting time = %f\n", (float)total_wt / (float)n); 
	printf("Average turn around time =%f\n ", (float)total_tat / (float)n); 
} 

// Driver code
int main() 
{ 
int num, quantum; 
	
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
	printf("Enter Quantum: ");
	scanf("%d", &quantum);
	
	sortArrival(num,mat);
	findavgTime(mat, num, quantum); 
	return 0; 
} 

