#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char location[51];
    char city[51];
    int price;
    int rooms;
    int bathroom;
    int carpark;
    char type[51];
    char furnish[51];
}Furniture;

Furniture sortedFurniture[5001];

void printHeader() // To print header
{
    printf("\n%-30s %-20s %-10s %-6s %-8s %-7s %-15s %-15s\n", 
		   "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
}

void displayData(Furniture arr[], int count, int row) // To display data
{
    printHeader();
    if(row > 0)
    {
        if(row > count)
        {
            row = count;
        }
        int i;
        for(i = 0; i < row; i++)
        {
            printf("%-30s %-20s %-10d %-6d %-8d %-7d %-15s %-15s\n", arr[i].location, arr[i].city, arr[i].price,
                   arr[i].rooms, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].furnish);
        }
    }
}

void searchData(Furniture arr[], int count) // To search data
{
    char column[9];
    char dataFind[101];
    printf("Choose column: ");
    scanf("%s", column);
    getchar();

    printf("What data do you want to find? ");
    scanf("%s", dataFind);
    getchar();

    int dataFoundFlag = 0;
    int i;
    for(i = 0; i < count; i++)
    {
        if((strcmp(column, "Location") == 0 && strcmp(arr[i].location, dataFind) == 0) ||
            (strcmp(column, "City") == 0 && strcmp(arr[i].city, dataFind) == 0) ||
            (strcmp(column, "Price") == 0 && arr[i].price == atoi(dataFind)) ||
            (strcmp(column, "Rooms") == 0 && arr[i].rooms == atoi(dataFind)) ||
            (strcmp(column, "Bathroom") == 0 && arr[i].bathroom == atoi(dataFind)) ||
            (strcmp(column, "Carpark") == 0 && arr[i].carpark == atoi(dataFind)) ||
            (strcmp(column, "Type") == 0 && strcmp(arr[i].type, dataFind) == 0) ||
            (strcmp(column, "Furnish") == 0 && strcmp(arr[i].furnish, dataFind) == 0))
            {
            if(dataFoundFlag == 0)
            {
                printHeader();
                dataFoundFlag = 1;
            }
            printf("%-30s %-20s %-10d %-6d %-8d %-7d %-15s %-15s\n", arr[i].location, arr[i].city, arr[i].price,
                   arr[i].rooms, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].furnish);
        }
    }

    if(dataFoundFlag == 0)
    {
        printf("Data not found!\n");
    }
}

void merge(Furniture arr[], int left, int mid, int right, char* column) // Merge sort function
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Furniture L[n1], R[n2];
    
    for(i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2) 
    {
        int compareResult;
        if(strcmp(column, "Location") == 0) 
        {
            compareResult = strcmp(L[i].location, R[j].location);
        } 
        else if(strcmp(column, "City") == 0) 
        {
            compareResult = strcmp(L[i].city, R[j].city);
        } 
        else if(strcmp(column, "Type") == 0) 
        {
            compareResult = strcmp(L[i].type, R[j].type);
        } 
        else if(strcmp(column, "Furnish") == 0) 
        {
            compareResult = strcmp(L[i].furnish, R[j].furnish);
        } 
        else if(strcmp(column, "Price") == 0) 
        {
            compareResult = L[i].price - R[j].price;
        } 
        else if(strcmp(column, "Rooms") == 0) 
        {
            compareResult = L[i].rooms - R[j].rooms;
        } 
        else if(strcmp(column, "Bathroom") == 0) 
        {
            compareResult = L[i].bathroom - R[j].bathroom;
        } 
        else if(strcmp(column, "Carpark") == 0) 
        {
            compareResult = L[i].carpark - R[j].carpark;
        }

        if(compareResult < 0)
        {
            arr[k] = L[i];
            i++;
        } 
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Furniture arr[], int left, int right, char* column) // Algorithm to sort data
{
    if(left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, column);
        mergeSort(arr, mid + 1, right, column);

        merge(arr, left, mid, right, column);
    }
}

void sortData(Furniture arr[], int count, int *isSorted) // Function to sort data
{
    char column[9];
    char sortOption[4];
    printf("Choose column: ");
    scanf("%s", column);

    printf("Sort ascending or descending? ");
    scanf("%s", sortOption);

    if(strcmp(sortOption, "asc") == 0)
    {
        mergeSort(arr, 0, count - 1, column);
        printHeader();
        int i;
        for(i = 0; i < 10; i++) 
        {
            printf("%-30s %-20s %-10d %-6d %-8d %-7d %-15s %-15s\n", arr[i].location, arr[i].city, arr[i].price,
                arr[i].rooms, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].furnish);
            for(int j = 0; j <= count; j++)
            {
                sortedFurniture[j] = arr[j];
            }
        }
        *isSorted = 1;
    }
    else if(strcmp(sortOption, "dsc") == 0)
    {
        mergeSort(arr, 0, count - 1, column);
        printHeader();
        int i;
        for(i = count-1; i >= count-10; i--) 
        {
            printf("%-30s %-20s %-10d %-6d %-8d %-7d %-15s %-15s\n", arr[i].location, arr[i].city, arr[i].price,
                arr[i].rooms, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].furnish);
            int j;
            for(j = 0; j <= count; j++)
            {
                sortedFurniture[j] = arr[j];
            }
        }
        *isSorted = 2;
    }
}

void exportData(Furniture arr[], int count, char* fileName) // Export the data to a file (default)
{
    FILE *fp = fopen(fileName, "w");
    if(!fp)
    {
        printf("Error exporting data!\n");
        return;
    }

    fprintf(fp, "Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish\n");

    int i;
    for(i = 0; i < count; i++)
    {
        fprintf(fp, "%s,%s,%d,%d,%d,%d,%s,%s\n", arr[i].location, arr[i].city, arr[i].price,
                arr[i].rooms, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].furnish);
    }

    fclose(fp);
    printf("Data successfully written to file %s!\n", fileName);
}

void exportDataDsc(Furniture arr[], int count, char* fileName) // Export the data if the sorting is descending
{
    FILE *fp = fopen(fileName, "w");
    if(!fp)
    {
        printf("Error exporting data!\n");
        return;
    }

    fprintf(fp, "Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish\n");

    int i;
    for(i = count-1; i >= 0; i--)
    {
        fprintf(fp, "%s,%s,%d,%d,%d,%d,%s,%s\n", arr[i].location, arr[i].city, arr[i].price,
                arr[i].rooms, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].furnish);
    }

    fclose(fp);
    printf("Data successfully written to file %s!\n", fileName);
}

int menu() // Menu function
{
    int choice;
    printf("Furniture Listing Manager\n=========================\n");
    printf("What do you want to do?\n");
    printf("1. Display Data\n");
    printf("2. Search Data\n");
    printf("3. Sort Data\n");
    printf("4. Export Data\n");
    printf("5. Exit\n");
    printf("Your Choice: ");
    scanf("%d", &choice); getchar();
    return choice;
}

int main() // Main function
{
    int isSorted = 0;
    int input;
    do
    {
        system("cls");
        input = menu();
    
        FILE *fp = fopen("file.csv", "r");

        if(!fp)
        {
            printf("Data Kosong\n");
            exit(0);
        }

        Furniture furniture[5001];

        char header[100];
        fscanf(fp, "%[^\n]\n", header);
        
        int i = 0, count = 0;
        while(fscanf(fp,"%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", furniture[i].location, furniture[i].city, &furniture[i].price,
                    &furniture[i].rooms, &furniture[i].bathroom, &furniture[i].carpark, furniture[i].type, furniture[i].furnish) != EOF)
        {
            i++;
            count++;
        }
        
        fclose(fp);

        switch(input) 
        {
            case 1: 
            {
                int row;
                do{
                    printf("Number of rows: ");
                    scanf("%d", &row);
                }
                while(row <= 0);

                displayData(furniture, count, row);
                system("pause");
                break;
            }
            case 2:
            {
                searchData(furniture, count);
                system("pause");
                break;
            }
            case 3:{
                sortData(furniture, count, &isSorted);
                system("pause");
                break;
            }
            case 4:{
                char fileName[1024];
                printf("File name: ");
                scanf("%s", fileName);
                getchar();

                if(strstr(fileName, ".csv") == NULL)
                {
                    strcat(fileName, ".csv");
                }
                if(isSorted == 1)
                {
                    exportData(sortedFurniture, count, fileName);
                }
                else if(isSorted == 2)
                {
                    exportDataDsc(sortedFurniture, count, fileName);
                }
                else
                {
                    exportData(furniture, count, fileName);
                }
                system("pause");
                break;
            }
        }
    }
    while(input !=5);
    return 0;
}
