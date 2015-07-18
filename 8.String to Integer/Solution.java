public class Solution {
    public int myAtoi(String str) {
        int len = str.length(),sign=1,pre=1;
        long s=0;
        for(int i=0;i<len;i++)
        {
            char ci =str.charAt(i); 
            if(ci>='0'&&ci<='9')
            {
                pre=0;
                s=s*10+ci-'0';
                if(s*sign>Integer.MAX_VALUE)
                    return Integer.MAX_VALUE;
                if(s*sign<Integer.MIN_VALUE)
                    return Integer.MIN_VALUE;
            }
            else if(pre==0)
                break;
            else if(ci=='-')
            {
                sign=-1;
                pre=0;
            }
            else if(ci=='+')
            {
                sign=1;
                pre=0;
            }
            else if(ci!=' ')
                break;
        }
        return (int)(sign*s);
    }
    public static void main(String args[])
    {
        Solution s=new Solution();
        String a=" 010";
        System.out.println(s.myAtoi(a));
    }
}
