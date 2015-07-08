
public class wzt {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int m=nums2.length;
        double ans = getKth(nums1,0,n,nums2,0,m,(n+m-1)/2);
        if((n+m)%2==0)
            ans=(ans+getKth(nums1,0,n,nums2,0,m,(n+m-1)/2+1))/2.0;
        return ans;
    }
    double getKth(int[] a,int al,int ar,int[] b,int bl,int br,int k)
    {
        System.out.println(al+","+ar+"-+-"+bl+","+br+":"+k);
        if(k==0)return Math.min(a[al],b[bl]);
        if(k==1)return Math.max(a[al],b[bl]);
        int am=(al+ar)/2;
        int bm=(bl+br)/2;
        if(am-al+bm-bl>=k)
        {
            if(a[am]<b[bm])
                return getKth(a,al,ar,b,bl,bm,k);
            else 
                return getKth(a,al,am,b,bl,br,k);
        }
        else 
        {
            if(a[am]<b[bm])
                return getKth(a,am,ar,b,bl,br,k-(am-al));
            else 
                return getKth(a,al,ar,b,bm,br,k-(bm-bl));
        }
    }
    public static void main(String args[])
    {
        int[] a=new int[]{1,2};
        int[] b=new int[]{3,4,4,5};
        wzt ss= new wzt();
        System.out.println(ss.findMedianSortedArrays(a,b));
    }
}
