void swap(float *a, int i, int j)
{
    float temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}