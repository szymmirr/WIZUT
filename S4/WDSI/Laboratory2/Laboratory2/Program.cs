using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace Laboratory2 {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("Hello World");
            //Stopwatch sw = Stopwatch.StartNew();

            //string sudokuPattern = "123456789123456789123456789123456789123456789123456789123456789123456789123456789"; //sudoku w postaci stringa np.: " 010330218... "
            //string sudokuPattern = "294167358315489627678253491456312879983574216721698534562941783839726145147835962"; //sudoku w postaci stringa np.: " 010330218... "
            //string connect4Pattern = "204107358315489627678053491406302879983004216721698534002941783039726045147835062"; //sudoku w postaci stringa np.: " 010330218... "
            //string sudokuPattern = "004100308010000620008200400000302809000070000701608000562001703030000040100005000";
            string connect4Pattern = "223221112222232322222222222222222222";

            Connect4State startState = new Connect4State(connect4Pattern);
            Connect4Search searcher = new Connect4Search(startState, false, 2);
            searcher.DoSearch();

            //IState state = searcher.Solutions[0];
            //IState state = new Connect4State((Connect4State)connect4Pattern);
            IState state = startState;

            List<Connect4State> solutionPath = new List<Connect4State>();

            while (state != null)
            {
                solutionPath.Add((Connect4State)state);
                state = state.Parent;
            }
            solutionPath.Reverse();

            foreach (Connect4State s in solutionPath)
            {
                s.Print();
            }

            while (true)
            {
                Console.WriteLine("Podaj numer");
                int czytaj = Convert.ToInt32(Console.ReadLine());
                //connect4Pattern[2] = "222222222222222222222222222222222222";
                while(connect4Pattern[czytaj]!='2')
                {
                    czytaj += 6;
                }

                char[] arr = connect4Pattern.ToCharArray();
                arr[czytaj] = '1'; //moze '1'


                connect4Pattern = new string(arr);
                startState = new Connect4State(connect4Pattern);
                searcher = new Connect4Search(startState, true, 2);
                searcher.DoSearch();

                //state = searcher.Solutions[0];
                state = new Connect4State(connect4Pattern);

                solutionPath = new List<Connect4State>();

                while (state != null)
                {
                    solutionPath.Add((Connect4State)state);
                    state = state.Parent;
                }
                solutionPath.Reverse();
                double maxheur = 0;
                foreach (KeyValuePair<string, double> kvp in searcher.MovesMiniMaxes)
                {
                    //if(KeyValuePair<>)
                    if (kvp.Value > maxheur)
                    {
                        maxheur = kvp.Value;
                    }
                    Console.WriteLine("COOOOO333333");
                    Console.WriteLine("Key: {0} Values: {1}", kvp.Key, kvp.Value);
                }
                foreach (Connect4State s in solutionPath)
                {
                    s.Print();
                }

            }

            //sw.Stop();
            //Console.WriteLine("Czas: " + sw.ElapsedMilliseconds + "ms");
            Console.ReadKey();
        }
    }
}
