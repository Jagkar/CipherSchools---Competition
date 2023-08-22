#include<iostream>
using namespace std;

int maxArea(int array[], int n){
  int maxWater=0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      //finding minimum height of 2 selected vertical lines
      int minHeight=array[i];
      if (minHeight>array[j]) minHeight=array[j];

      //finding the current area covered by the water
      int currentWater=(j-i)*minHeight;

      // comparing the maximum area till now with the area of next iteration
      if (currentWater>maxWater) maxWater=currentWater;
    }
  }
  return maxWater;
}

int main()
{
  int n; //length of array
  cin>>n;
  int height[n];
  for (int i = 0; i < n; i++)
  {
    cin>>height[i];
  }
  cout<<maxArea(height,n)<<endl;
  return 0;
}
