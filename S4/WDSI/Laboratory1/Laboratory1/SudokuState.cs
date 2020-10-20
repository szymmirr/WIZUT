using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Laboratory1
{
    public class SudokuState : State
    {
        private string id ; 
        
        public override string ID {
                get { return this . id ; }
        }
        
        public override double ComputeHeuristicGrade()
        {
            //double heur=0; 
            double zera = 0;
            int[] wiersz = { 0,0,0,0,0,0,0,0,0 };
            int[] kolumna = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            //Console.WriteLine("dwa");
            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    wiersz[j] = this.table[i, j];
                    if (this.table[i, j] == 0)
                    {
                        zera = zera + 1;
                    }
                }
                Array.Sort(wiersz);
                for (int j = 0; j < 8; j++)
                {
                    //Console.Write(wiersz[j] + " ");
                    if (wiersz[j] == wiersz[j + 1] && wiersz[j]!=0)
                    {
                        return double.PositiveInfinity;
                    }
                }
            }

            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    kolumna[j] = this.table[j, i];
                }
                Array.Sort(kolumna);
                for (int j = 0; j < 8; j++)
                {
                    //Console.Write("kolumna" + kolumna[j] + " ");
                    if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                    {
                        return double.PositiveInfinity;
                    }
                }
            }
            int k = 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }
            k = 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 3; j < 6; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }
            k = 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 6; j < 9; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }
            k = 0;
            for (int i = 3; i < 6; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }
            k = 0;
            for (int i = 3; i < 6; ++i)
            {
                for (int j = 3; j < 6; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }
            k = 0;
            for (int i = 3; i < 6; ++i)
            {
                for (int j = 6; j < 9; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }
            k = 0;
            for (int i = 6; i < 9; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }
            k = 0;
            for (int i = 6; i < 9; ++i)
            {
                for (int j = 3; j < 6; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }
            k = 0;
            for (int i = 6; i < 9; ++i)
            {
                for (int j = 6; j < 9; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    k++;
                }
            }
            Array.Sort(kolumna);
            for (int j = 0; j < 8; j++)
            {
                //Console.Write("kolumna" + kolumna[j] + " ");
                if (kolumna[j] == kolumna[j + 1] && kolumna[j] != 0)
                {
                    return double.PositiveInfinity;
                }
            }

            return zera;
        }

        public void Print ()
        {
            //Console.BufferHeight = 1000;
            //Console.WriteLine("lolprint");
            for (int i = 0; i < GRID_SIZE; ++i)
            {
                if (i == 3)
                {
                    Console.WriteLine("-------------------");
                }
                if (i == 6)
                {
                    Console.WriteLine("-------------------");
                }
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    if(this.table[i, j]==0)
                    {
                        Console.Write("  ");
                    }
                    else
                    {
                        Console.Write(table[i, j]);
                        Console.Write(" ");
                    }
                    if (j == 2)
                    {
                        Console.Write("|");
                    }
                    if (j == 5)
                    {
                        Console.Write("|");
                    }
                    if (j == 8)
                    {
                        Console.WriteLine();
                    }
                }
            }
            Console.WriteLine();
            Console.WriteLine();
            // ...
        }

        public const int SMALL_GRID_SIZE = 3;

        public const int GRID_SIZE = SMALL_GRID_SIZE * SMALL_GRID_SIZE ;


        //private string id ;

        private int [ ,] table ;

        public int [ ,] Table {
        get { return this . table ; }
        set { this . table = value ; }
        }

        // reszta implementacji

        public SudokuState ( string sudokuPattern ) : base () {
            if ( sudokuPattern . Length != GRID_SIZE * GRID_SIZE ) {
            throw new ArgumentException (" SudokuSring posiada niewlasciwa dlugosc .") ;
            }

            // utworzenie id
            this . id = sudokuPattern ;

            // stworzenie i wypelnienie wewnetrzej tablicy przechowujacej stan sudoku
            this . table = new int [ GRID_SIZE , GRID_SIZE ];

            for(int i = 0; i < GRID_SIZE ; ++ i ) {
            for (int j = 0; j < GRID_SIZE ; ++ j ) {
            this . table [i , j ] = sudokuPattern [ i * GRID_SIZE + j ]- 48;
            }
            }

            // obliczenie heurystyki
            //Console.WriteLine("lol");
            //Console.WriteLine("jeden");
            this . h = ComputeHeuristicGrade () ;
        }

        public SudokuState ( SudokuState parent , int newValue , int x , int y ) :
            base ( parent ) {
            this . table = new int [ GRID_SIZE , GRID_SIZE ];
            // Skopiowanie stanu sudoku do nowej tabeli
            Array . Copy ( parent . table , this . table , this . table . Length ) ;
            // Ustawienie nowej wartosci w wybranym polu sudoku
            this . table [x , y ] = newValue ;

            // Utworzenie nowego id odpowiadajacemu aktualnemu stanowi planszy
            StringBuilder builder = new StringBuilder ( parent . id ) ;
            builder [ x * GRID_SIZE + y ] = ( char ) ( newValue + 48) ;
            this . id = builder . ToString () ;

            //Console.WriteLine("lol2");
            this . h = ComputeHeuristicGrade () ;
        }

    }
}
