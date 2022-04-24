#include <../thirdparty/ctest.h>
#include <lib/move.h>

char desk[desk_size][desk_size]
        = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

motion mt;


CTEST(quiet_step_suite, step_size_false)
{
    char step[10] = "Nb1-c3B";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_true)
{
    char step[10] = "e2-e4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_true2)
{
    char step[10] = "Nb1-c3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_false)
{
    char step[10] = "e2/e4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_false2)
{
    char step[10] = "Be1'e4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, small_type)
{
    char step[10] = "nb1-c3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, move_to_non_empty_cell)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', ' ', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', 'p', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "e2-e4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_pawn_2_step_false)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', 'P', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', ' ', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    char step[10] = "d3-d5";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, move_from_empty_cell)
{
    char step[10] = "e3-e4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, going_out_of_field)
{
    char step[10] = "e0-e2";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, white_must_go_true)
{
    char step[10] = "e2-e4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, black_must_go_true)
{
    char step[10] = "e7-e5";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, false, false);

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, white_must_go_false)
{
    char step[10] = "e7-e5";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, black_must_go_false)
{
    char step[10] = "e2-e4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, false, false);

    ASSERT_FALSE(result);
}

CTEST(take_step_suite, take_empty)
{
    char step[10] = "e2xe4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(take_step_suite, friendly_fire)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', 'P', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', ' ', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "e2xf3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(pawn_step, type_is_true)
{
    char step[10] = "e2-e3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(pawn_step, type_is_false)
{
    char step[10] = "e1-e2";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(pawn_step, step_back)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', 'p', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', ' ', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "e4-e2";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(pawn_step, take_true)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', ' ', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', 'p', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "e2xf3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(pawn_step, take_false)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', ' ', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', 'p', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "f2xf3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(pawn_step, stepping_over_is_false)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', ' ', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', 'p', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "e2-e4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(king_step, type_is_true)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', 'P', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', ' ', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "Ke1-e2";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(king_step, type_is_false)
{
    char step[10] = "Ke2-e3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(king_step, step_is_true)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', 'P', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', ' ', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "Ke1-e2";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(king_step, step_is_false)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', 'P', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', ' ', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "Ke1-e3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_FALSE(result);
}

CTEST(king_step, step_is_true_2)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', 'P', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', ' ', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "Ke1-d2";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(king_step, take_is_true)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', ' ', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'p', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "Ke1xe2";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(queen_step, step_is_true)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', ' ', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char step[10] = "Qd1-d4";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}

CTEST(queen_step, step_is_true2)
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', ' ', 'K', 'B', 'N', 'R'}};
    char step[10] = "Qd3-f3";
    translate(step, &mt);
    bool result = movecheck(step, mt, desk, true, false);

    ASSERT_TRUE(result);
}
