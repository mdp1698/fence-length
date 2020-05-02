//Name:Mit Patel

#include<stdio.h>
#include <math.h>


int main()
{
    int length;
    printf("Measurement of the fencing needed (feet): ");
    scanf("%d",&length);
    while(length<=0)
    {
        printf("Please enter an integer > 0: ");
        scanf("%d",&length);
    }
    int smaller_panel_length;
    printf("Enter the size of smaller panel in feet: ");
    scanf("%d",&smaller_panel_length);
    while(smaller_panel_length<=0){
        printf("Please enter an integer > 0: ");
        scanf("%d",&smaller_panel_length);
    }
    
    int larger_panel_length = smaller_panel_length+2;
    
    int equalCount = length/(2*smaller_panel_length+2);
    
    int smaller_count=0,larger_count=0, special_length=0;
    
    if(equalCount*(smaller_panel_length+larger_panel_length)==length)
    {
        smaller_count=larger_count=equalCount;
        special_length =0;
    }
    else
    {
        int total = equalCount*(smaller_panel_length+larger_panel_length);
        int remaining = length - total;
        if(remaining<smaller_panel_length)
        {
            smaller_count=larger_count=equalCount;
            special_length=remaining;
        }
        else
        {
            smaller_count= equalCount+1;
            larger_count = (length - smaller_count*smaller_panel_length)/larger_panel_length;
            special_length = length - smaller_count*smaller_panel_length - larger_count*larger_panel_length;
            
        }
        if(special_length>=smaller_panel_length)
        {
            smaller_count +=special_length/smaller_panel_length;
            special_length%=smaller_panel_length;
        }
    }
    
    printf("The larger panel will be %d\n\n",larger_panel_length);
    printf("Happy Building!!\n\n");
    
    printf("The fence will need %d qty %d foot panel(s) and %d qty %d foot panel(s)\n",
           smaller_count,smaller_panel_length,larger_count,larger_panel_length   );
    
    if(special_length!=0)
    {
        printf("\nPlus a special order %d foot panel.\n",special_length);
    }
    
    
}


