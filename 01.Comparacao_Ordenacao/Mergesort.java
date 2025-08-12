import java.util.Random;

public class Mergesort {
    private int[] numbers;
    private int[] helper;

    private int number;

    public void sort(int[] values) {
        this.numbers = values;
        number = values.length;
        this.helper = new int[number];
        mergesort(0, number - 1);
    }

    private void mergesort(int low, int high) {
        // Check if low is smaller then high, if not then the array is sorted
        if (low < high) {
            // Get the index of the element which is in the middle
            int middle = (low + high) / 2;
            // Sort the left side of the array
            mergesort(low, middle);
            // Sort the right side of the array
            mergesort(middle + 1, high);
            // Combine them both
            merge(low, middle, high);
        }
    }

    private void merge(int low, int middle, int high) {

        // Copy both parts into the helper array
        for (int i = low; i <= high; i++) {
            helper[i] = numbers[i];
        }

        int i = low;
        int j = middle + 1;
        int k = low;
        // Copy the smallest values from either the left or the right side back
        // to the original array
        while (i <= middle && j <= high) {
            if (helper[i] <= helper[j]) {
                numbers[k] = helper[i];
                i++;
            } else {
                numbers[k] = helper[j];
                j++;
            }
            k++;
        }
        // Copy the rest of the left side of the array into the target array
        while (i <= middle) {
            numbers[k] = helper[i];
            k++;
            i++;
        }
    }

    public static void main(String args[]) {
        Random r = new Random();
        int MAX = 100000;
        for(int n=500; n<=MAX; n+=500) {
            int[] data = new int[n];
            for(int i=0; i<data.length; i++)
                data[i] = r.nextInt(data.length*10);

            Mergesort ms = new Mergesort();
            long start = System.nanoTime();
            ms.sort(data);
            long end = System.nanoTime();
            double tempo = (end-start)/1e9;
            System.out.printf("%d %f\n",n,tempo);
        }
        //for(int i=0; i<data.length; i++)
        //    System.out.print(data[i]+" ");
        //System.out.println();
    }
}
