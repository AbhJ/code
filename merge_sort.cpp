void merge(int l,int mid,int r){
    for (int i=l; i<mid; i++){
      B[i]=p[i];
  }
  B[mid]=inf;
  for (int i=mid; i<r; i++){
      B[i+1]=p[i];
  }
  B[r+1]=inf;
  int i=l, j=mid+1;
    for (int k=l; k<r; k++){
    if (B[i]<=B[j]) p[k]=B[i++];
    else p[k]=B[j++];
    }
}
void m(int l,int r){
  if(r-l<2)return;
  int M=l+r+1>>1;
  m(l,M);
  m(M,r);
  for(int i=l;i<M;i++){
    num+=(lower_bound(p+M,p+r,p[i]+t)-(p+M));
  }
  merge(l,M,r);
}