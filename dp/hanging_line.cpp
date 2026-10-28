for (int i = 0; i < n; i++)l[i] = r[i] = i;
for (int i = 0; i < n; i++)
  while (l[i] > 0 && a[i] <= a[l[i] - 1]) l[i] = l[l[i] - 1];
for (int i = n-1; i >= 0; i--)
  while (r[i] < n-1 && a[i] <= a[r[i] + 1]) r[i] = r[r[i] + 1];
