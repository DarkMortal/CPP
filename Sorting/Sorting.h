#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

namespace Quick_SORT{
    template <class X>
    void Swap(X &a,X &b){ a+=b; b=a-b; a-=b; }
    namespace ASCENDING{
        template <class X>
        int DIVIDE(X* arr,int index,int len){
            int LOW=index+1;
            int HIGH=len;
            do{
                while(arr[LOW]<=arr[index]) LOW++;
                while(arr[HIGH]>arr[index]) HIGH--;
                if(LOW<HIGH) Swap(arr[LOW],arr[HIGH]);
            }while(LOW<HIGH);
            if(index!=HIGH) Swap(arr[index],arr[HIGH]);
            return HIGH;
        }
        template <class X>
        void SORT(X* arr,int START,int END){
            int p_index=0;
            if(START<END){
                p_index=DIVIDE(arr,START,END);
                SORT(arr,START,p_index-1);
                SORT(arr,p_index+1,END);
            }
        }
    }
    namespace DESCENDING{
        template <class X>
        int DIVIDE(X* arr,int index,int len){
            int LOW=len;
            int HIGH=index+1;
            do{
                while(arr[LOW]<=arr[index]) LOW--;
                while(arr[HIGH]>arr[index]) HIGH++;
                if(LOW>HIGH) Swap(arr[LOW],arr[HIGH]);
            }while(LOW>HIGH);
            if(index!=LOW) Swap(arr[index],arr[LOW]);
            return LOW;
        }
        template <class X>
        void SORT(X* arr,int START,int END){
            int p_index=0;
            if(START<END){
                p_index=DIVIDE(arr,START,END);
                SORT(arr,p_index+1,END);
                SORT(arr,START+1,p_index-1);
            }
        }
    }
}

namespace Merge_SORT{
    namespace ASCENDING{
        template <class X>
        void MERGE(X* a,int mid,int low,int high){
            int i=low,j=mid+1,k=low;
            X c[high-low+1];
            while(i<=mid && j<=high){
                if(a[i]<a[j]){
                    c[k]=a[i];
                    k++; i++;
                }
                else{
                    c[k]=a[j];
                    k++; j++;
                }
            }
            while(i<=mid){
                c[k]=a[i];
                k++; i++;
            }
            while(j<=high){
                c[k]=a[j];
                k++; j++;
            }
            for(i=low;i<=high;i++) a[i]=c[i];
        }

        template <class X>
        void SORT(X* A,int low,int high){
            int mid;
            if(low<high){
                mid=(low+high)/2;
                SORT(A,low,mid);
                SORT(A,mid+1,high);
                MERGE(A,mid,low,high);
            }
        }
    }
    namespace DESCENDING{
        template <typename X>
        void MERGE(X* a,int mid,int low,int high){
            int i=low,j=mid+1,k=low;
            X c[high-low+1];
            while(i<=mid && j<=high){
                if(a[i]>a[j]){
                    c[k]=a[i];
                    k++; i++;
                }
                else{
                    c[k]=a[j];
                    k++; j++;
                }
            }
            while(i<=mid){
                c[k]=a[i];
                k++; i++;
            }
            while(j<=high){
                c[k]=a[j];
                k++; j++;
            }
            for(i=low;i<=high;i++) a[i]=c[i];
        }

        template <typename X>
        void SORT(X* A,int low,int high){
            int mid;
            if(low<high){
                mid=(low+high)/2;
                SORT(A,low,mid);
                SORT(A,mid+1,high);
                MERGE(A,mid,low,high);
            }
        }
    }
}
#endif // SORTING_H_INCLUDED
