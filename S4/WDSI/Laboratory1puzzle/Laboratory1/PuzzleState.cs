using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Laboratory1
{
    public class PuzzleState : State
    {
        private string id ;
        
        public override string ID {
                get { return this . id ; }
        }

        public override double ComputeHeuristicGrade()
        {
            //return; //heurystyka z wykladu
            //Console.WriteLine("lol3");
            //double heur=0;
            double misplaced = 0;
            int[] kolumna = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            //Console.WriteLine("dwa");
            
            int k = 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    kolumna[k] = this.table[i, j];
                    if(kolumna[k]!=k&&kolumna[k]!=0)
                    {
                        misplaced += 1;
                    }
                    k++;
                }
            }
            Console.WriteLine(misplaced);
            Print();
            return misplaced;
        }

        public void Print ()
        {
            //Console.BufferHeight = 1000;
            //Console.WriteLine("lolprint");
            for (int i = 0; i < GRID_SIZE; ++i)
            {
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
                        Console.WriteLine();
                    }
                }
                
            }
            Console.WriteLine();
            // ...
        }

        //public const int SMALL_GRID_SIZE = 3;

        public const int GRID_SIZE = 3;


        //private string id ;

        private int [ ,] table ;

        public int [ ,] Table {
        get { return this . table ; }
        set { this . table = value ; }
        }

        // reszta implementacji

        public PuzzleState ( string sudokuPattern ) : base () {
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

        public PuzzleState ( PuzzleState parent , int newValue , int x , int y, int xNew , int yNew ) :
            base ( parent ) {
            this . table = new int [ GRID_SIZE , GRID_SIZE ];
            // Skopiowanie stanu sudoku do nowej tabeli
            Array . Copy ( parent . table , this . table , this . table . Length ) ;
            // Ustawienie nowej wartosci w wybranym polu sudoku
            this . table [x , y ] = 0 ;
            this.table[xNew, yNew] = newValue;
            // Utworzenie nowego id odpowiadajacemu aktualnemu stanowi planszy
            StringBuilder builder = new StringBuilder ( parent . id ) ;
            builder [ x * GRID_SIZE + y ] = ( char ) ( newValue + 48) ;
            this . id = builder . ToString () ;

            //Console.WriteLine("lol2");
            this . h = ComputeHeuristicGrade () ;
            this.g = parent.g + 1;
        }

    }
}
