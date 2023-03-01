/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package mergesort;

/**
 *
 * @author Bilal
 */
public class MergeSort {
    
    void merge(int arr[],int l,int m,int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        
        int L1[] = new int[n1];
        int R1[] = new int[n2];
        
        for (int i = 0;i<n1;i++)
        {
            L1[i] =arr [l+i];
        }
        for (int i = 0;i<n2;i++)
        {
            R1[i] =arr [m+1+i];
        }
        for (int x = 0;x<arr.length;x++)
            System.out.print(arr[x]+" ");
        System.out.println();
        
        int i = 0; int j= 0; int k=l;
        while (i<n1 && j < n2)
        {
            if (L1[i]<R1[j])
            {
                arr[k] = L1[i];
                k++;i++;
            }
            else
            {
                arr[k] = R1[j];
                k++;j++;
            }
        }
        for(;i<n1;i++)
        {
            arr[k++] = L1[i];
        }
        for(;j<n2;j++)
        {
            arr[k] = R1[j];
                k++;
        }
    }
    void sort(int arr[],int l, int r)
    {
        if(l<r)
        {
            int m = (l+r)/2;
            
            sort(arr, l,m);
            sort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int arr[] = {5,3,70,4,40,6,16,12};
        MergeSort obj = new MergeSort();
        obj.sort(arr, 0, arr.length-1);
        for (int i = 0;i<arr.length;i++)
            System.out.print(arr[i]+" ");
    }
    
}
