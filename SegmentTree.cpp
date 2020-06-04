vli segment(4*maxn+1,0);
lli n;
void build(vli &a, lli v=1, lli tl=0, lli tr=n-1) {
    if (tl == tr) segment[v] = a[tl];
    else {
        lli tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        segment[v] = segment[v*2] + segment[v*2+1];
    }
}

void update(lli pos, lli new_val, lli v=1, lli tl=0, lli tr=n-1) {
    if (tl == tr) segment[v] = new_val;
    else {
        lli tm = (tl + tr) / 2;
        if (pos <= tm) update(pos, new_val, v*2, tl, tm);
        else update(pos, new_val,v*2+1, tm+1, tr);
        segment[v] = segment[v*2] + segment[v*2+1];
    }
}

lli sum(lli l, lli r, lli v=1, lli tl=0, lli tr=n-1) {
    if (l > r) return 0;
    if (l == tl && r == tr) return segment[v];
    lli tm = (tl + tr) / 2;
    return sum(l, min(r, tm),v*2, tl, tm) + sum(max(l, tm+1), r,v*2+1, tm+1, tr);
}