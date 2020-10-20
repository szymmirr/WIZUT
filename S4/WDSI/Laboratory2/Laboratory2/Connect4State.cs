using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Laboratory2
{
    public class Connect4State : State
    {
        private string id;
        public override string ID
        {
            get
            {
                return this.id;
            }
        }

        public override double ComputeHeuristicGrade()
        {
            double heurystyka = 0;
            double heurystykaX = 0;
            double heurystykaO = 0;
            //int[] wiersz = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            //int[] kolumna = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    if (this.table != null)
                    {
                        if (this.table[i, j] == 3)
                        {
                            Console.WriteLine("czeker111");
                            heurystykaX = 1;
                            Console.WriteLine("heurx1: {0}", heurystykaX);
                            if (this.table[i, j + 1] == 3)
                            {
                                Console.WriteLine("czeker11111111111111");
                                heurystykaX = 4;
                                Console.WriteLine("heurx2: {0}", heurystykaX);
                                j += 1;
                                if (this.table[i, j + 1] == 3)
                                {
                                    heurystykaX = 16;
                                    Console.WriteLine("heurx3: {0}", heurystykaX);
                                    j += 1;
                                    if (this.table[i, j + 1] == 3)
                                    {
                                        return double.PositiveInfinity;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Console.WriteLine("czeker");
            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    if (this.table != null)
                    {
                        if (this.table[j, i] == 3)
                        {
                            heurystykaX = 1;
                            Console.WriteLine("heurx1: {0}", heurystykaX);
                            if (this.table[j + 1, i] == 3)
                            {
                                heurystykaX = 4;
                                Console.WriteLine("heurx2: {0}", heurystykaX);
                                j += 1;
                                if (this.table[j + 1, i] == 3)
                                {
                                    heurystykaX = 16;
                                    Console.WriteLine("heurx3: {0}", heurystykaX);
                                    j += 1;
                                    if (this.table[j + 1, i] == 3)
                                    {
                                        return double.PositiveInfinity;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE-2; ++j)
                {
                    if (this.table != null)
                    {
                        if (this.table[i, j] == 1)
                        {
                            Console.WriteLine("czeker111");
                            heurystykaO = -1;
                            Console.WriteLine("heuro1: {0}", heurystykaO);
                            if (this.table[i, j + 1] == 1)
                            {
                                Console.WriteLine("czeker11111111111111");
                                heurystykaO = -4;
                                Console.WriteLine("heuro2: {0}", heurystykaO);
                                j += 1;
                                if (this.table[i, j + 1] == 1)
                                {
                                    heurystykaO = -16;
                                    Console.WriteLine("heuro3: {0}", heurystykaO);
                                    j += 1;
                                    if (this.table[i, j + 1] == 1)
                                    {
                                        Console.WriteLine("WYGRANKO");
                                        return double.NegativeInfinity;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Console.WriteLine("czeker");
            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    if (this.table != null)
                    {
                        if (this.table[j, i] == 1)
                        {
                            heurystykaO = 1;
                            Console.WriteLine("heuro1: {0}", heurystykaO);
                            if (this.table[j + 1, i] == 1)
                            {
                                heurystykaO = 4;
                                Console.WriteLine("heuro2: {0}", heurystykaO);
                                j += 1;
                                if (this.table[j + 1, i] == 1)
                                {
                                    heurystykaO = 16;
                                    Console.WriteLine("heuro3: {0}", heurystykaO);
                                    j += 1;
                                    if (this.table[j + 1, i] == 1)
                                    {
                                        Console.WriteLine("WYGRANKO");
                                        return double.PositiveInfinity;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            heurystyka = heurystykaX + heurystykaO;
            Console.WriteLine("heur: {0}",heurystyka);
            return heurystyka;
        }

        public Connect4State(Connect4State parent /* pozostale niezbedne parametry */) : base(parent)
        {
            this.id = parent.id; //tu
            this.depth = parent.depth + 0.5;
            if (parent.rootMove == null)
            {
                this.rootMove = this.id;
            }
            else
            {
                this.rootMove = parent.rootMove;
            }
        }

        public void Print()
        {
            //Console.BufferHeight = 1000;
            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    if (this.table[i, j] == 2)
                    {
                        Console.Write("- ");
                    }
                    else
                    {
                        Console.Write(table[i, j]);
                        Console.Write(" ");
                    }
                    if (j == GRID_SIZE-1)
                    {
                        Console.WriteLine();
                    }
                }

            }
            Console.WriteLine();
            // ...
        }

        //public const int SMALL_GRID_SIZE = 3;

        public const int GRID_SIZE = 6;


        //private string id ;

        private int[,] table;

        public int[,] Table
        {
            get { return this.table; }
            set { this.table = value; }
        }

        // reszta implementacji

        public Connect4State(string Connect4Pattern) : base () {
            if (Connect4Pattern.Length != GRID_SIZE * GRID_SIZE)
            {
                throw new ArgumentException(" SudokuSring posiada niewlasciwa dlugosc .");
            }

            // utworzenie id
            this.id = Connect4Pattern;

            // stworzenie i wypelnienie wewnetrzej tablicy przechowujacej stan sudoku
            this.table = new int[GRID_SIZE, GRID_SIZE];

            for (int i = 0; i < GRID_SIZE; ++i)
            {
                for (int j = 0; j < GRID_SIZE; ++j)
                {
                    this.table[i, j] = Connect4Pattern[i * GRID_SIZE + j] - 48;
                }
            }

            // obliczenie heurystyki
            //Console.WriteLine("lol");
            //Console.WriteLine("jeden");
            this.h = ComputeHeuristicGrade();
        }

        /*public Connect4State(Connect4State parent, int newValue, int x, int y) :
            base ( parent ) {
            this.table = new int[GRID_SIZE, GRID_SIZE];
            // Skopiowanie stanu sudoku do nowej tabeli
            Array.Copy(parent.table, this.table, this.table.Length);
            // Ustawienie nowej wartosci w wybranym polu sudoku
            this.table[x, y] = newValue;

            // Utworzenie nowego id odpowiadajacemu aktualnemu stanowi planszy
            StringBuilder builder = new StringBuilder(parent.id);
            builder[x * GRID_SIZE + y] = (char)(newValue + 48);
            this.id = builder.ToString();

            //Console.WriteLine("lol2");
            this.h = ComputeHeuristicGrade();
        }*/

    }
}
