import java.util.ArrayList;

public class Solution {
    public static void main(String[] args) {
        ArrayList<Integer> inputArrayList = new ArrayList<Integer>();
        ArrayList<Integer> outputArrayList = new ArrayList<Integer>();

        inputArrayList.add(1);
        inputArrayList.add(2);
        inputArrayList.add(3);
        inputArrayList.add(4);
        inputArrayList.add(5);

        // ---- Method 1: Naive method with O(n^2) Complexity -----------

        /*for (int i=0; i< inputArrayList.size(); i++){
            int prod = 1;
            for(int j=0; j< inputArrayList.size(); j++){
                if (i==j){
                    continue;
                }
                prod = prod * inputArrayList.get(j);
            }
            outputArrayList.add(prod);
        }

        ----------------- End of method 1 --------------
         */

        /*
         ---------- Method 2: Not allowed though as per question bonus ---------
        int totalProduct = 1;

        for (Integer integer : inputArrayList) {
            totalProduct *= integer;
        }
        for (int j=0; j<inputArrayList.size(); j++){
            inputArrayList.set(j, (totalProduct/inputArrayList.get(j)) );
        }
        ------------------- End of method 2 ------------------
         */

        // Method 3: Calculating left and right product of every element
        int temp1 = 1;
        outputArrayList.add(1);
        for(int i=1; i<inputArrayList.size();i++){
            temp1 = temp1 * inputArrayList.get(i-1);
            outputArrayList.add(temp1);
        }
        temp1 = 1;
        for(int j=inputArrayList.size() - 2; j>=0; j--){
            temp1 = temp1 * inputArrayList.get(j+1);
            outputArrayList.set(j, temp1 * outputArrayList.get(j) );
        }
        System.out.println(inputArrayList);
        System.out.println(outputArrayList);
    }
}
