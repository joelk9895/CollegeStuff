package Algorithms;

public class Union {

    public static void main(String[] args) {
        int[] arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int[] check = new int[11];
        for (int i : arr) {
            check[i] = i;
        }
        union(arr, check, 1, 2);
        union(arr, check, 2, 3);
        union(arr, check, 4, 5);
        union(arr, check, 6, 7);
        union(arr, check, 4, 6);

        for (int i : check) {
            System.out.print(i + " ");
        }
        System.out.println();
        System.out.println(find(check, 5, 6
        
    }

    static void union(int[] arr, int[] check, int a, int b) {
        int temp = check[a];
        for (int i = 0; i < arr.length; i++) {
            if (check[i] == temp) {
                check[i] = check[b];
            }
        }
    }

    static boolean find(int[] arr, int a, int b) {
        if (arr[a] == arr[b]) {
            return true;
        }
        return false;
    }
}