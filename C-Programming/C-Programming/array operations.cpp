#include<stdio.h>

int main(){

    int n;

    int arr[9] = {10,20,30,50,100,60};

    printf("1. Insert \n 2. Delete \n 3. Linear Search\n 4. Binary Search \n 5. selection sort \n");

    scanf("%d", &n);

    switch(n){

        case 1:
            int index, num; 
            printf("after which Index ? \n");
            scanf("%d", &index);

            printf("What number ? \n");
            scanf("%d", &num);

            for(int i = 6; i > index; i--){

                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }

            arr[index + 1] = num;

            for(int i = 0; i < 8; i++){
                 printf("%d ", arr[i]);
            }
        
            break;

        case 2:

            int in; 
            printf("after which Index ? \n");
            scanf("%d", &in);

            for(int i = in + 1; i < 7; i++){

                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }

            for(int i = 0; i < 6; i++){
                 printf("%d ", arr[i]);
            }
            
            break;

        case 3:

            int key;
            printf("Which element ?");
            scanf("%d", &key);

            for(int i = 0; i < 7; i++){

                if(arr[i] == key){

                    printf("Element found at %d index", i);
                    break;
                }
            }

            break;

        case 4:

            int ke;
            printf("Which element ?");
            scanf("%d", &ke);

            int i = 0, l = 7, mid = (i + l)/2;

            while(i <= l){

                if(arr[mid] == ke){

                    printf("Element found at %d index", mid);
                    break;
                }

                else if(arr[mid] < ke)
                    i = mid + 1;

                else 
                    l = mid - 1;

                mid = (i + l)/2;        
            }

            break;

        case5:

            for(int i = 0; i < 7; i++){

                int least = i;

                for(int j = i; j < 7; j++){

                    if(arr[j] < arr[least])
                        
                        least = j;
                }

                int temp = arr[i];
                arr[i] = arr[least];
                arr[least] = temp;
            }

            for(int i = 0; i < 7; i++)
            {
			  printf("%d ", arr[i]);
	         }
	     }
	 }

                








