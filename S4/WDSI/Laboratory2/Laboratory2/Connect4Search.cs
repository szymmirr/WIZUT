using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Laboratory2
{
    public class Connect4Search : AlphaBetaSearcher
    {
        /*public override string ID
        {
            get
            {
                //throw new NotImplementedException();
            }
        }

        public override double ComputeHeuristicGrade()
        {
            //throw new NotImplementedException();
        }*/
        public Connect4Search(IState startState, bool isMaximizingPlayerFirst, int maximumDepth) : base(startState, isMaximizingPlayerFirst, maximumDepth)
        { }

        protected override void buildChildren(IState parent)
        {
            Console.WriteLine("COOOOO");
            Connect4State state = (Connect4State)parent;
            for (int i = 0; i < Connect4State.GRID_SIZE; ++i)
            {
                for (int j = 0; j < Connect4State.GRID_SIZE; ++j)
                {
                    if (state.Table != null)
                    {
                        if (state.Table[i, j] == 2)
                        {
                            // wstawianie kolejnych potomkow w wolne pole
                            for (int k = 1; k < Connect4State.GRID_SIZE + 1; ++k)
                            {
                                Connect4State child = new Connect4State(state);
                                parent.Children.Add(child);
                            }
                            break;
                        }
                    }
                }
            }
            double maxheur = 0;
            Console.WriteLine("COOOOO111111");
            foreach (KeyValuePair<string, double> kvp in this.MovesMiniMaxes)
            {
                //if(KeyValuePair<>)
                /*if (kvp.Value > maxheur)
                {
                    maxheur = kvp.Value;
                }*/
                Console.WriteLine("COOOOO222222");
                Console.WriteLine("Key: {0} Values: {1}",kvp.Key,kvp.Value);
            }
            //return 
        }
        /*protected override bool isSolution(IState state)
        {
            return state.H == 0.0;
        }*/
        //return State.H == 0.0;
    }
}
