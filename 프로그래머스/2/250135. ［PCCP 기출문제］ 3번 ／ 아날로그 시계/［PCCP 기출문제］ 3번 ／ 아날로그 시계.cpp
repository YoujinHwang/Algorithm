#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int t1=h1*3600+m1*60+s1;
    int t2=h2*3600+m2*60+s2;
    //시작 시점(t1)에서 시침/분침과 초침이 겹치는 경우는 따로 새주어야함. 0시 0분 0초일때와 12시 0분 0초일때 -> 왜 이 경우만?
    if(t1==0||t1==12*3600) answer+=1; 
    while(t1<t2) {
        //시침: 1시간-30도 -> 1초당 30/3600=1/120도 이동
        //분침: 1분-6도->1초당 6/60 = 1/10도 이동
        //초침: 1초당 6도 이동
        int hh=t1/3600;
        int mm=(t1%3600)/60;
        int ss=(t1%3600)%60;
        double h_start=(hh%12)*30+mm*0.5+ss*(1/120.0);
        double m_start=mm*6+ss*0.1;
        double s_start=ss*6;
        
        int hh2=(t1+1)/3600;
        int mm2=((t1+1)%3600)/60;
        int ss2=((t1+1)%3600)%60;
        double h_nxt=(hh2%12)*30+mm2*0.5+ss2*(1/120.0);
        double m_nxt=mm2*6+ss2*0.1;
        double s_nxt=ss2*6;
        
        //다음 위치가 360도인 경우 0도로 계산되어 카운트 되지 않는 경우 방지
        // double h_nxt=(t1+1)/120%360;
        // if(h_nxt==0) h_nxt=360;
        // double m_nxt=(t1+1)/10%360;
        // if(m_nxt==0) m_nxt=360;
        // double s_nxt=(t1+1)*6%360;
        // if(s_nxt==0) s_nxt=360;
        
        //이동한 후 지나치거나 같아진 경우 알람 울림
        if(s_start<m_start &&s_nxt>=m_nxt) answer+=1;
        else if (s_start==354&&m_nxt>354) answer+=1;
        if(s_start<h_start && s_nxt>=h_nxt) answer+=1;
        else if (s_start==354&&h_nxt>354) answer+=1;
        
        if(s_nxt==h_nxt&&h_nxt==m_nxt) answer-=1;
        //왜 이 경우에만 동시에?
        
        t1+=1;
        
    }
    
    return answer;
}



