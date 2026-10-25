struct LiChao_ST{
  struct line{
    ll m,c;
    line(ll _m=0,ll _c=0){ m=_m; c=_c; }
    ll eval(ll x){ return m*x+c; } // overflow
  };
  struct node{
    node *l,*r; line f;
    node(line v){ f=v; l=r=NULL; }
  };
  typedef node* pnode;
  pnode root; ll sz,ql,qr;
#define mid ((l+r)>>1)
  void insert(line v,ll l,ll r,pnode &nd){
    /*if(!(ql<=l&&r<=qr)){
      if(!nd) nd=new node(line(0,-INF)); //min:INF,max:-INF 
      if(ql<=mid) insert(v,l,mid,nd->l);
      if(qr>mid) insert(v,mid+1,r,nd->r);
      return;
    } //used for adding segment */
    if(!nd){ nd=new node(v); return; }
    ll trl=nd->f.eval(l),trr=nd->f.eval(r);
    ll vl=v.eval(l),vr=v.eval(r);
	// for minimum
    // if(trl<=vl&&trr<=vr) return;
	// if(trl>vl&&trr>vr) { nd->f=v; return; }
	// if(trl>vl) swap(nd->f,v);
    // if(nd->f.eval(mid)<v.eval(mid))
    //   insert(v,mid+1,r,nd->r);
    // else swap(nd->f,v),insert(v,l,mid,nd->l);
	// for maximum
	if(trl >= vl && trr >= vr) return;
    if(trl < vl && trr < vr) { nd->f = v; return; }
    if(trl < vl) swap(nd->f, v);
    if(nd->f.eval(mid) < v.eval(mid)) {
      swap(nd->f, v); insert(v, l, mid, nd->l);
    } else { 
      insert(v, mid + 1, r, nd->r);
    }
  }
  ll query(ll x,ll l,ll r,pnode &nd){
    if(!nd) return -INF;//min:INF,max:-INF 
    if(l==r) return nd->f.eval(x);
    if(mid>=x)
      return max(nd->f.eval(x),query(x,l,mid,nd->l));
    return max(nd->f.eval(x),query(x,mid+1,r,nd->r));
  }
  /* -sz<=ll query_x<=sz */
  void init(ll _sz){ sz=_sz+1; root=NULL; }//最多開x的值域
  void add_line(ll m,ll c,ll l=-INF,ll r=INF){
    line v(m,c); ql=l; qr=r; insert(v,-sz,sz,root);
  }
  ll query(ll x) { return query(x,-sz,sz,root); }
};
