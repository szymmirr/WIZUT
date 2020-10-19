using System;
using System.Numerics;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        public class Rownanie
        {
            List<int> dane_we = new List<int>();
            float d;
            double md;
            List<Complex> z = new List<Complex>();
            public
            Rownanie()
            {
                int dana1, dana2, dana3;
                dana1 = Convert.ToInt32(Console.ReadLine());
                dana2 = Convert.ToInt32(Console.ReadLine());
                dana3 = Convert.ToInt32(Console.ReadLine());
                dane_we.Add(dana1);
                dane_we.Add(dana2);
                dane_we.Add(dana3);
                z.Add(0);
                z.Add(0);
                z.Add(0);
                z.Add(0);
                z.Add(0);
                z.Add(0);
            }
            ~Rownanie()
            {
                dane_we.RemoveAt(dane_we.Count - 1);
                dane_we.RemoveAt(dane_we.Count - 1);
                dane_we.RemoveAt(dane_we.Count - 1);
                dane_we.Clear();
                z.RemoveAt(z.Count - 1);
                z.RemoveAt(z.Count - 1);
                z.RemoveAt(z.Count - 1);
                z.RemoveAt(z.Count - 1);
                z.RemoveAt(z.Count - 1);
                z.RemoveAt(z.Count - 1);
                z.Clear();
            }
            List<int> getdane() { return dane_we; }
            List<Complex> getzesp() { return z; }
            float getd() { return d; }
            void setd(float dd) { d = dd; }
            double getmd() { return md; }
            void setmd(double mdd) { md = mdd; }
            public
            void wyswietl_rownanie()
            {
                if (dane_we[0] != 1 && dane_we[0] != 0 && dane_we[0] != -1)
                {
                    Console.Write(dane_we[0]);
                }
                if (dane_we[0] != 0)
                {
                    if (dane_we[0] == -1)
                    {
                        Console.Write("-");
                    }
                    Console.Write("xx");
                    if (dane_we[1] > 0)
                    {
                        Console.Write("+");
                    }
                }
                if (dane_we[1] != 1 && dane_we[1] != 0 && dane_we[1] != -1)
                {
                    Console.Write(dane_we[1]);
                }
                if (dane_we[1] != 0)
                {
                    if (dane_we[1] == -1)
                    {
                        Console.Write("-");
                    }
                    Console.Write("x");
                    if (dane_we[2] > 0)
                    {
                        Console.Write("+");
                    }
                }
                if (dane_we[2] != 0)
                {
                    Console.Write(dane_we[2]);
                }
                if (dane_we[0] == 0 && dane_we[1] == 0 && dane_we[2] == 0)
                {
                    Console.Write(0);
                }
                Console.Write("=0");
                Console.WriteLine();
            }

            public void oblicz_d()
            {
                List<int> dane_we = getdane();
                float d = getd();
                if (dane_we[0] != 0)
                {
                    d = (dane_we[1] * dane_we[1]) - (4 * dane_we[0] * dane_we[2]);
                    Console.Write("d=");
                    Console.Write(d);
                    Console.WriteLine();
                    setd(d);
                }
                else
                {
                    setd(0);
                }
            }

            public void oblicz_pierwiastki()
            {
                float d = getd();
                if (dane_we[0] != 0)
                {
                    if (d > 0)
                    {
                        z[0] = ((-dane_we[1] * 1.0) - Math.Sqrt(d)) / (2 * (dane_we[0] * 1.0));
                        Console.Write("x1v=");
                        Console.Write(z[0].Real.ToString());
                        Console.WriteLine();
                        z[1] = (((-dane_we[1] * 1.0) + Math.Sqrt(d)) * 1.0) / ((2 * (dane_we[0] * 1.0)) * 1.0);
                        Console.Write("x2v=");
                        Console.Write(z[1].Real.ToString());
                        Console.WriteLine();
                    }
                    if (d == 0)
                    {
                        z[0] = (-dane_we[1] * 1.0) / ((2 * (dane_we[0] * 1.0)) * 1.0);
                        Console.Write("x1v=");
                        Console.Write(z[0].Real.ToString());
                        Console.WriteLine();
                    }
                    if (d < 0)
                    {
                        z[0] = (-dane_we[1] * 1.0) / ((2 * dane_we[0]) * 1.0);
                        z[1] = z[0];
                        Complex c1 = new Complex(z[0].Real, (Math.Sqrt(Math.Abs(d))) / (2 * (dane_we[0] * 1.0)));
                        z[0] = c1;
                        c1 = new Complex(z[1].Real, -z[0].Imaginary);
                        z[1] = c1;
                        formatuj_l_zesp();
                    }
                }
                if (dane_we[0] == 0 && dane_we[1] != 0)
                {
                    double x1v = ((-dane_we[2] * 1.0) / (dane_we[1] * 1.0));
                    z[0] = x1v;
                    Console.Write("x1v=");
                    Console.Write(z[0].Real);
                    Console.WriteLine();
                }
                if (dane_we[0] == 0 && dane_we[1] == 0 && dane_we[2] != 0)
                {
                    Console.Write("Rownanie sprzeczne");
                }
                if (dane_we[0] == 0 && dane_we[1] == 0 && dane_we[2] == 0)
                {
                    Console.Write("Rownanie tozsamosciowe");
                }
            }

            public void dodaj()
            {
                if (d > 0)
                {
                    z[2] = z[0] + z[1];
                }
                if (d < 0)
                {
                    z[2] = z[0] + z[1];
                    Complex c1 = new Complex(z[2].Real, z[0].Imaginary + z[1].Imaginary);
                    z[2] = c1;
                }
            }

            public void odejmij()
            {
                if (d > 0)
                {
                    z[3] = z[0] - z[1];
                }
                if (d < 0)
                {
                    z[3] = z[0] - z[1];
                    Complex c1 = new Complex(z[3].Real, z[0].Imaginary - z[1].Imaginary);
                    z[3] = c1;
                }
            }

            public void pomnoz()
            {
                if (d > 0)
                {
                    z[4] = (z[0]) * (z[1]);
                }
                if (d < 0)
                {
                    z[4] = (z[0].Real) * (z[1].Real) - (z[0].Imaginary) * (z[1].Imaginary);
                    Complex c1 = new Complex(z[4].Real, (z[0].Real) * (z[1].Imaginary) + (z[0].Real) * (z[1].Imaginary));
                    z[4] = c1;
                }
            }

            public void podziel()
            {
                if (d > 0)
                {
                    if (z[1].Real != 0)
                    {
                        z[5] = (z[0]) / (z[1]);
                    }
                }
                if (d < 0)
                {
                    z[5] = ((z[0].Real) * (z[1].Real) + (z[0].Imaginary) * (z[1].Imaginary)) / (((z[1].Real) * (z[1].Real)) + ((z[1].Imaginary) * (z[1].Imaginary)));
                    Complex c1 = new Complex(z[5].Real, (z[0].Real) * (z[1].Imaginary) - (z[0].Imaginary) * (z[1].Imaginary)) / (((z[1].Real) * (z[1].Real)) + ((z[1].Imaginary) * (z[1].Imaginary)));
                    z[5] = c1;
                }
            }
            public void wyswietl_wynik()
            {
                float d = getd();
                if (dane_we[0] != 0)
                {
                    if (d > 0)
                    {
                        Console.Write("sv=");
                        Console.Write(z[2].Real);
                        Console.WriteLine();
                        Console.Write("rv=");
                        Console.Write(z[3].Real);
                        Console.WriteLine();
                        Console.Write("ilv=");
                        Console.Write(z[4].Real);
                        Console.WriteLine();
                        Console.Write("irv=");
                        Console.Write(z[5].Real);
                        Console.WriteLine();
                    }
                    if (d < 0)
                    {
                        Console.Write("sv=");
                        Console.Write(z[2].Real);
                        Console.WriteLine();
                        Console.Write("sn=");
                        Console.Write(z[2].Imaginary);
                        Console.WriteLine();
                        Console.Write("rv=");
                        Console.Write(z[3].Real);
                        Console.WriteLine();
                        Console.Write("rn=");
                        Console.Write(z[3].Imaginary);
                        Console.WriteLine();
                        Console.Write("ilv=");
                        Console.Write(z[4].Real);
                        Console.WriteLine();
                        Console.Write("iln=");
                        Console.Write(z[4].Imaginary);
                        Console.WriteLine();
                        Console.Write("irv=");
                        Console.Write(z[5].Real);
                        Console.WriteLine();
                        Console.Write("irn=");
                        Console.Write(z[5].Imaginary);
                        Console.WriteLine();
                    }
                }
            }

            public void my_sqrt()
            {
                float t1 = 0, t2 = 1;
                if (t1 != t2)
                {
                    t1 = t2;
                    t2 = (t1 + Math.Abs(d) / t1) / 2;
                }
                if (t1 != t2)
                {
                    t1 = t2;
                    t2 = (t1 + Math.Abs(d) / t1) / 2;
                }
                if (t1 != t2)
                {
                    t1 = t2;
                    t2 = (t1 + Math.Abs(d) / t1) / 2;
                }
                if (t1 != t2)
                {
                    t1 = t2;
                    t2 = (t1 + Math.Abs(d) / t1) / 2;
                }
                if (t1 != t2)
                {
                    t1 = t2;
                    t2 = (t1 + Math.Abs(d) / t1) / 2;
                }
                if (t1 != t2)
                {
                    t1 = t2;
                    t2 = (t1 + Math.Abs(d) / t1) / 2;
                }
                Console.Write("sqrt(d)=");
                Console.Write(Math.Sqrt(Math.Abs(d)));
                Console.WriteLine();
                Console.Write("my_sqrt(d)=");
                Console.Write(t2);
                Console.WriteLine();
                if (t2 - Math.Sqrt(Math.Abs(d)) < 0.000000001)
                {
                    Console.Write("my_sqrt(d)-sqrt(d)=");
                    Console.Write(0);
                    Console.WriteLine();
                }
                else
                {
                    Console.Write("my_sqrt(d)-Math.Sqrt(d)=");
                    Console.Write(t2 - Math.Sqrt(Math.Abs(d)));
                    Console.WriteLine();
                }
            }

            public void formatuj_l_zesp()
            {
                Console.Write("z1=");
                Console.Write(z[0].Real);
                if (z[0].Imaginary >= 0)
                {
                    Console.Write("+");
                }
                if (z[0].Imaginary == -1)
                {
                    Console.Write("-");
                }
                if (z[0].Imaginary != 1 && z[0].Imaginary != -1 && z[0].Imaginary != 0)
                {
                    Console.Write(z[0].Imaginary);
                }
                if (z[0].Imaginary != 0)
                {
                    Console.Write("*");
                }
                Console.Write("i");
                Console.WriteLine();
                Console.Write("z2=");
                Console.Write(z[1].Real);
                if (z[1].Imaginary >= 0)
                {
                    Console.Write("+");
                }
                if (z[1].Imaginary == -1)
                {
                    Console.Write("-");
                }
                if (z[1].Imaginary != 1 && z[1].Imaginary != -1 && z[1].Imaginary != 0)
                {
                    Console.Write(z[1].Imaginary);
                }
                if (z[1].Imaginary != 0)
                {
                    Console.Write("*");
                }
                Console.Write("i");
                Console.WriteLine();
            }

            public void oblicz_modul()
            {
                double md = getmd();
                md = Math.Sqrt(Math.Abs((z[0].Real * z[0].Real) + ((z[0].Imaginary) * (z[0].Imaginary))));
                Console.Write("md=");
                Console.Write(md);
                Console.WriteLine();
                setmd(md);
            }
        };

        static void Main(string[] args)
        {
            Rownanie obiekt = new Rownanie();
            obiekt.wyswietl_rownanie();
            obiekt.oblicz_d();
            obiekt.oblicz_pierwiastki();
            obiekt.my_sqrt();
            obiekt.dodaj();
            obiekt.odejmij();
            obiekt.pomnoz();
            obiekt.podziel();
            obiekt.wyswietl_wynik();
            obiekt.oblicz_modul();
            Console.ReadLine();
        }
    }
}