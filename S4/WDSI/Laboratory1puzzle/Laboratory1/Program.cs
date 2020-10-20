using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace Laboratory1 {
    class Program {
            static void Main( string [] args) {
            Stopwatch sw = Stopwatch.StartNew();

            //string sudokuPattern = "123456789123456789123456789123456789123456789123456789123456789123456789123456789"; //sudoku w postaci stringa np.: " 010330218... "
            //string sudokuPattern = "294167358315489627678253491456312879983574216721698534562941783839726145147835962"; //sudoku w postaci stringa np.: " 010330218... "
            string sudokuPattern = "102345678"; //sudoku w postaci stringa np.: " 010330218... "
            //string sudokuPattern = "004100308010000620008200400000302809000070000701608000562001703030000040100005000";

        PuzzleState startState = new PuzzleState ( sudokuPattern );
        PuzzleSearch searcher = new PuzzleSearch ( startState );
        searcher . DoSearch ();

        IState state = searcher . Solutions [0];

        List < PuzzleState > solutionPath = new List < PuzzleState >();

        while (state != null) {
        solutionPath .Add (( PuzzleState )state);
        state = state . Parent ;
        }
        solutionPath . Reverse ();

        foreach ( PuzzleState s in solutionPath ){
        s.Print ();
        }
            sw.Stop();
            Console.WriteLine("Czas: "+sw.ElapsedMilliseconds+"ms");
            Console.ReadKey();
    }
        
    }
}
