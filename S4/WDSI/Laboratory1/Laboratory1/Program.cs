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
            string sudokuPattern = "204107358315489627678053491406302879983004216721698534002941783039726045147835062"; //sudoku w postaci stringa np.: " 010330218... "
            //string sudokuPattern = "004100308010000620008200400000302809000070000701608000562001703030000040100005000";

        SudokuState startState = new SudokuState ( sudokuPattern );
        SudokuSearch searcher = new SudokuSearch ( startState );
        searcher . DoSearch ();

        IState state = searcher . Solutions [0];

        List < SudokuState > solutionPath = new List < SudokuState >();

        while (state != null) {
        solutionPath .Add (( SudokuState )state);
        state = state . Parent ;
        }
        solutionPath . Reverse ();

        foreach ( SudokuState s in solutionPath ){
        s.Print ();
        }
            sw.Stop();
            Console.WriteLine("Czas: "+sw.ElapsedMilliseconds+"ms");
            Console.ReadKey();
    }
        
    }
}
