void merge(int arr[], int l, int m, int r) {

  int ln=m-l+1;
  int rn=r-m;
  int larr[ln];
  int rarr[rn];
  for(int i=0;i<ln;i++){
    larr[i]=arr[l+i];
  }
  for(int i=0;i<rn;i++){
    rarr[i]=arr[m+1+i];
  }
  while(l<ln && r>rn){
    
  }
}
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int mid = l + ((r - l) / 2);
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}
