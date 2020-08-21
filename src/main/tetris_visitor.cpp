#include "tetris_visitor.h"

TetrisVisitor::TetrisVisitor( TetrisBoard& param_board, Game& param_game )
  : board( param_board ), game( param_game )
{
}

void TetrisVisitor::visitTetrisPiece( TetrisPiece& piece )
{
  if( board.has_landed( piece ) )
  {
    piece.set_falling( false );
    game.transfer_piece_to_board( piece );
    game.add_piece();
  }
  else if( !board.has_landed( piece ) && !piece.is_falling() )
  {
    while( !board.has_landed( piece ) )
    {
      piece.fall();
    }
    game.transfer_piece_to_board( piece );
    game.add_piece();
  }
}

void TetrisVisitor::visitTetrisBoard( TetrisBoard& board )
{
  if( board.new_score() )
  {
    game.score += board.get_score();
    std::cout << game.score << std::endl;
  }

  if( board.full() )
  {
    game.engine -> quit();
  }
}
