using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Laboratory1
{
    public class PuzzleSearch : AStarSearch
    {
        public PuzzleSearch(PuzzleState state) : base(state, true, true) { }

        protected override void buildChildren ( IState parent ) {
        PuzzleState state = ( PuzzleState ) parent ;

            // poszukiwanie wolnego pola
            //Console.WriteLine("trzy");
            for (int i = 0; i < PuzzleState.GRID_SIZE; ++i)
            {
                for (int j = 0; j < PuzzleState.GRID_SIZE; ++j)
                {
                    if (state.Table[i, j] == 0)
                    {
                        // wstawianie kolejnych potomkow w wolne pole
                        /*for (int k = 1; k < PuzzleState.GRID_SIZE + 1; ++k)
                        {
                            PuzzleState child = new PuzzleState(state, k, i, j);
                            parent.Children.Add(child);
                        }*/
                        if(i==0&&j==0)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[0, 1], 0, 1, 0, 0);
                            parent.Children.Add(child);

                            child = new PuzzleState(state, state.Table[1, 0], 1, 0, 0, 0);
                            parent.Children.Add(child);
                        }
                        if (i == 0 && j == 1)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[0, 0], 0, 0, 0, 1);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[0, 2], 0, 2, 0, 1);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[1, 1], 1, 1, 0, 1);
                            parent.Children.Add(child);
                        }
                        if (i == 0 && j == 2)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[0, 1], 0, 1, 0, 2);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[1, 2], 1, 2, 0, 2);
                            parent.Children.Add(child);
                        }
                        if (i == 1 && j == 0)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[0, 0], 0, 0, 1, 0);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[1, 1], 1, 1, 1, 0);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[2, 0], 2, 0, 1, 0);
                            parent.Children.Add(child);
                        }
                        if (i == 1 && j == 1)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[0, 1], 0, 1, 1, 1);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[1, 0], 1, 0, 1, 1);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[1, 2], 1, 2, 1, 1);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[2, 1], 2, 1, 1, 1);
                            parent.Children.Add(child);
                        }
                        if (i == 1 && j == 2)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[0, 2], 0, 2, 1, 2);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[1, 1], 1, 1, 1, 2);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[2, 2], 2, 2, 1, 2);
                            parent.Children.Add(child);
                        }
                        if (i == 2 && j == 0)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[1, 0], 1, 0, 2, 0);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[2, 1], 2, 1, 2, 0);
                            parent.Children.Add(child);
                        }
                        if (i == 2 && j == 1)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[2, 0], 2, 0, 2, 1);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[1, 1], 1, 1, 2, 1);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[2, 2], 2, 2, 2, 1);
                            parent.Children.Add(child);
                        }
                        if (i == 2 && j == 2)
                        {
                            PuzzleState child = new PuzzleState(state, state.Table[2, 1], 2, 1, 2, 2);
                            parent.Children.Add(child);
                            child = new PuzzleState(state, state.Table[1, 2], 1, 2, 2, 2);
                            parent.Children.Add(child);
                        }
                        break;
                    }
                }
            }
        }

        protected override bool isSolution ( IState state) {
        return state .H == 0.0;
        }
    }
}
