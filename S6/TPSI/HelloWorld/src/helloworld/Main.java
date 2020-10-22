package helloworld;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        double liczbyR[] = new double[6];
        Integer liczbyC[] = new Integer[6];
        //Integer GatunekPiwa[] = new Integer[3];
        
        for(int i=0; i<6; i++) {
            liczbyC[i] = (int)(Math.floor(Math.random() * 49));
        }
        Arrays.sort(liczbyC);
        
        for(int i=0; i<6; i++) {
            System.out.println(liczbyC[i]);
        }
        
        //System.out.println(liczbyC[i]);
        GatunekPiwa piwkoNaDzisWieczor = GatunekPiwa.PIWO_Z_BIEDRONKI;

        //System.out.println(piwkoNaDzisWieczor);
        
        GatunekPiwa piwo[] = new GatunekPiwa[3];

        for(int i=0; i<3; i++)
        {
            piwo[i] = GatunekPiwa.values()[(int)(Math.floor(Math.random()*5))];
            System.out.println(piwo[i]);
        }
        
        for(int i=0; i<3; i++) {
            switch(piwo[i])
            {
                case LAGER:
                    System.out.println("piwo jasne");
                    break;
                case PILZNER:
                    System.out.println("piwo jasne");
                    break;
                case PORTER:
                    System.out.println("piwo ciemne");
                    break;
                case STOUT:
                    System.out.println("piwo ciemne");
                    break;
                case PIWO_Z_BIEDRONKI:
                    System.out.println("piwo tanie");
                    break;
            } 
        }
        
    }
    
    enum GatunekPiwa {
    LAGER, PILZNER, PORTER, STOUT, PIWO_Z_BIEDRONKI
}
}
