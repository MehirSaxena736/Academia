public class Countoccurrence{
    public static void main(String[] args){
        int arr[]={2,3,2,5,2,6};
        int target=2;
    

        int count=occurrences(arr,target);
        System.out.println("the number"  + target +  "occurs"  + count +  "times in the array");
    }
    public static int occurrences(int arr[],int target)
    {
        int count=0;
        for(int num:arr){
            if (num==target){
                count++;
            }
        }
        return count;
    }
}
