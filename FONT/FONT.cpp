// Sau khi tèt nghi»p ¤i håc, Quang ¢ ngay lap tùc ÷ñc tuyon v o nhâm chuy¶n kiom tra c¡c lo¤i
// phæng chú c¡i ti ̧ng Anh vi ̧t th÷íng (tùc c¡c chú c¡i tø a  ̧n z) cõa mët cæng ty cæng ngh» câ ti ̧ng ð
// thung lông Silicon. Cæng vi»c cõa anh r§t ìn gi£n: o kiom tra mët phæng chú, Quang ch¿ c¦n in mët
// sè c¥u câ ¦y õ 26 chú c¡i ti ̧ng Anh vi ̧t th÷íng (hay cán gåi l c¥u °c bi»t) ÷ñc vi ̧t b¬ng phæng
// chú â ra gi§y, sau â anh s3 nh1⁄4n xem c¥u â træng câ hñp l1⁄2 v μp m­t hay khæng v · xu§t mët sè
// ch¿nh sûa cho ëi thi ̧t k ̧ phæng n ̧u th§y c¦n thi ̧t.
// Do Quang mîi v o l m vi»c n¶n anh hi»n khæng câ b§t cù c¥u °c bi»t n o o kiom tra c¡c
// phæng chú. V1⁄4 vay, trong ng y l m vi»c ¦u ti¶n cõa m1⁄4nh, Quang quy ̧t ành t¤o mët sè c¥u °c bi»t
// tø N tø ti ̧ng Anh trong quyon tø ion chuy¶n ng nh m anh ¢ câ s®n ð tr¶n m¡y. H¢y vi ̧t ch÷ìng
// tr1⁄4nh  ̧m sè c¥u °c bi»t kh¡c nhau m Quang câ tho t¤o ÷ñc, bi ̧t r¬ng theo ti¶u chu©n ng nh kiom
// tra phæng, méi tø ch¿ ÷ñc sû döng mët l¦n trong mët c¥u °c bi»t v hai c¥u °c bi»t ÷ñc coi l kh¡c
// nhau n ̧u tçn t¤i mët tø xu§t hi»n trong c¥u n y nh÷ng khæng xu§t hi»n ð c¥u kia.
// Dú li»u
// • Dáng thù nh§t gçm mët sè nguy¶n d÷ìng N (1 ≤ N ≤ 25) l sè tø trong quyon tø ion cõa Quang.
// • N dáng ti ̧p theo, méi dáng gçm mët x¥u ch¿ câ c¡c k1⁄2 tü tø a  ̧n z l mët tø ti ̧ng Anh trong
// quyon tø ion.
// Dú li»u v o £m b£o quyon tø ion cõa Quang khæng câ hai tø n o gièng nhau.
// K ̧t qu£
// • Gçm mët dáng duy nh§t chùa mët sè nguy¶n l sè c¥u °c bi»t kh¡c nhau m Quang câ tho t¤o
// ÷ñc.
#include <bits/stdc++.h>
using namespace std;
const int maxn = 26;

int n;
int mask[maxn];
int kq;
int tmp = 0;
int z = (1 << 26) - 1;

int Convert(string s)
{
    int l = s.size();
    int res = 0;
    for (int i = 0; i < l; i++)
        res = res | (1 << (s[i] - 'a'));
    return res;
}

//void PrintMask(int z){
//    for(int i=0;i<26;i++) cout<<((z>>i)%2);cout<<endl;
//}

void back(int i, int tmp)
{
    //    cout<<"Back("<<i<<" "<<tmp<<")\n";
    //    cout<<"-------->";PrintMask(tmp);
    if (i == n + 1)
    {
        if (tmp == z)
            kq++;
        return;
    }
    back(i + 1, tmp);
    back(i + 1, tmp | mask[i]);
}

int main()
{
    //    freopen("input.txt","r",stdin);
    //    cout<<"Z= "<<z<<endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        mask[i] = Convert(s);
        //        cout<<"Mask["<<i<<"]= "<<mask[i]<<endl;
        //        PrintMask(mask[i]);
    }
    kq = 0;
    back(1, 0);
    cout << kq;
}
