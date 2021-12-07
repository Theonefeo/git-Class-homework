/**
 * Merges two given sorted arrays into one
 *
 * @param a1 first sorted array
 * @param a2 second sorted array
 * @return new array[sortedArrays] containing all elemenets from a1 and a2, sorted
 */
import java.util.Arrays;

public class SortedArrays {
   public static void main(String[] args){

      int[] array = mergeArrays();

      System.out.println("SortedArrays");
   }
   public static int[] mergeArrays(){
      int[] a1 = new int[]{3,0,8,6,5};
      Arrays.sort(a1);
      int[] a2 = new int[]{1, 7, 2, 7, 5, 9};
      Arrays.sort(a2);
      int[] sortedArrays = new int[a1.length+a2.length];

      for(int i = 0, k = 0, m = 0; i<(a1.length+a2.length); i++, k++, m++){

         //Finding an array with a smaller size
         int sizeOfTheSmallerArray;
         boolean flag;

         if(a1.length<a2.length){
            sizeOfTheSmallerArray = a1.length;
            flag = true;
         }else{
            sizeOfTheSmallerArray = a2.length;
            flag = false;
         }

         //Filling in the resulting array
         while(sizeOfTheSmallerArray!=0 & k<a1.length & m<a2.length) {
            if (a1[k] < a2[m]) {
               sortedArrays[i] = a1[k];
               sortedArrays[i + 1] = a2[m];

               System.out.println(sortedArrays[i]);
               System.out.println(sortedArrays[i+1]);

            } else {
               sortedArrays[i] = a2[m];
               sortedArrays[i + 1] = a1[k];

               System.out.println(sortedArrays[i]);
               System.out.println(sortedArrays[i+1]);
            }
            sizeOfTheSmallerArray--;
            i++;
            k++;
            m++;
         }


         //In the case, when there is only one array left
         if(sizeOfTheSmallerArray==0){

            if(flag){
               for( ;i<(a1.length+a2.length) & m<a2.length; i++, m++){
                  sortedArrays[i] = a2[m];
                  System.out.println(sortedArrays[i]);
               }

            }else{
               for( ; i<a1.length+a2.length; i++, k++){
                  sortedArrays[i] = a1[k];
               }
            }

         }


      }
      return sortedArrays;
   }
}
