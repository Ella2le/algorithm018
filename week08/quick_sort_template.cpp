
//
// Created by lewang on 12/12/20.
//
//参考课堂上分享的java改写
//这里不申请新的空间进行操作,所以会有一些小技巧
public static void quickSort(vector<int> array, int begin, int end) {
    if(end <= begin) return;//??
    int pivot = partition(array,begin,end);
    quickSort(aray,begin,pivot - 1);
    quickSort(array,pivot + 1, end);
}

static int partition(vector<int> a, int begin, int end)
{
    int pivot  = end, counter = begin;
    for(int i = begin; i < end; i++) {
        if(a[i] < a[pivot]) {
            int temp = a[counter]; a[counter] = a[i]; a[i] = temp;
            counter ++;
        }
    }
    int temp = a[pivot]; a[pivot] = a[counter]; a[counter] = temp;
    return counter;
}

//调用
//quickSort(a,0,a.size() -1);