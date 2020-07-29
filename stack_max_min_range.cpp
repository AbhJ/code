for(int i=1;i<=n;i++){
    while(s.empty()==0 and a[s.top()]<a[i])s.pop();
    if(s.empty()==0)l[i]=s.top();
    s.push(i);
  }
  s=stack<int>();
  for(int i=n;i>=1;i--){
    while(s.empty()==0 and a[s.top()]<a[i])s.pop();
    if(s.empty()==0)r[i]=s.top();
    else r[i]=n+1;
    s.push(i);
  }
  for(int i=1;i<=n;i++)++l[i],--r[i];