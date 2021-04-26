package homeWork_Math;
//利用真值表，判断两个命题公式是否等价
/*如何利用循环将所有赋值全部表示出来。
*利用四层循环。首先四个值全为true，变化顺序为，从后往前从true》false
* 1 1 1 1 》 1 1 1 0 》 1 1 0 1 》 1 1 0 0 》 1 0 1 1 》 1 0 1 0...
* 1.将最后一个字符（d）的所有布尔值连带前几个字符的布尔值全部打出。
* 2.再将倒数第二个字符（c）布尔值改变，将最后一个字符的布尔值的所有可能打出。
* 3.将倒数第三个字符（b）布尔值改变，将倒数两个字符的所有布尔值排列打出。
* 4.最后将第一个字符（a）布尔值改变，将最后三个字符的所有布尔值排列打出。
* 5.利用逻辑联结词构成的命题公式的返回值。设置中间变量temp，如果最后两组布尔值有不相同的情况，改变temp的值。
* 6.判断最终temp的值与一开始是否相等，如果相等则两个命题公式等价，否则则不相等。
*
*/
public class Demo01 {
    public static void main(String[] args) {
        int temp = 1;
    boolean a=true,b=true,c=true,d=true;
        Print_Start();
        if(Enumerate(a,b,c,d,temp)==1){
            System.out.println("两个组合逻辑电路设计等价");
        }else{
            System.out.println("两个组合逻辑电路设计不等价");
        }
    }
    //打印所有命题公式
    public static void Print_Start(){
        System.out.print("a\t\tb\t\tc\t\td\t\t");
        System.out.print("a&&(!b)&&c&&(!d)\t");
        System.out.print("(!a)&&c\t\t");
        System.out.print("b||d\t");
        System.out.print("(!a)||!(b||d)\t");
        System.out.print("(a&&(!b)&&c&&(!d))||((!a)&&c)\t");
        System.out.println("((!a)||!(b||d))&&c");
    }
    public static void Print_Struct(boolean a,boolean b,boolean c,boolean d){
        System.out.print(a+"\t"+b+"\t"+c+"\t"+d+"\t\t");
        System.out.print((a&&(!b)&&c&&(!d))+"\t\t\t");
        System.out.print(((!a)&&c)+"\t\t");
        System.out.print((b||d)+"\t\t");
        System.out.print(((!a)||!(b||d))+"\t\t\t\t");
        System.out.print(((a&&(!b)&&c&&(!d))||((!a)&&c))+"\t\t\t\t\t\t\t");
        System.out.println(((!a)||!(b||d))&&c);
    }
    //枚举所有a,b,c,d所有可能组合
    public static int Enumerate(boolean a,boolean b,boolean c,boolean d,int temp){
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        Print_Struct(a,b,c,d);//打印此时a,b,c,d组合对应个命题公式的真值
                        if((((!a)||!(b||d))&&c)!=((a&&(!b)&&c&&(!d))||((!a)&&c))){
                            temp = 0;//如果temp变化，说明至少一组赋值使得两组命题公式真值不相等
                        }
                        d=false;
                    }
                    c=false;
                    d=true;
                }
                b=false;
                c=true;
            }
            a=false;
            b=true;
        }
        return temp;
    }
}
