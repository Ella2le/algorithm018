//
// Created by lewang on 12/12/20.
//

public static void mergeSort(vector<int> array, int left, int right) {
    if(right <= left) return;
    int mid = (left + right) >> 1;

    mergeSort(array,left,mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid ,right);
}
//归并模板!!!一定记住
//left ----mid ---- right ,都是有序的两段
public static void merge(vector<int> arr, int left, int mid, int right) {
    //额外的内存空间
    vector<int> temp = new int[right - left +1];//中间数组?? 只是一个数??;
    int i = left; //左边有序数组的起始位
    int j = mid + 1;//右边有序数组的起始位
    int k =0;//k是已经填入数组temp中的个数

    while(i <= mid && j <= right) {
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }


    while(i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    //把temp中的元素拷贝到原来需要排序的数组array中去
    for(int p = 0; p < temp.size(); p++) {
        arr[left + p] = temp[p];
    }
    //也可以用system.arraycopy(a,start1,b,start2,length) 不知道c++是否有对应的函数,到时候用memcpy试试
    //memcpy( dst, a, a_len );
    //memcpy( dst+a_len, b, b_len );


}