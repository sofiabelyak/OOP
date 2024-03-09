#include "select_action.h"

err_t select_action(Actions action, user_interaction_t event)
{
    static figure_t figure = figure_init();
    err_t rc = OK;

    switch (action)
    {
        case DRAW:
            rc = draw_figure(figure, event.canvas);
            break;
        case LOAD:
            rc = load_figure(&figure, event.file_name);
            break;
        case SCALE:
            rc = scale_figure(&figure, &event.change);
            break;
        case SPIN:
            rc = spin_figure(&figure, &event.change);
            break;
        case MOVE:
            rc = move_figure(&figure, &event.change);
            break;
        case SAVE:
            rc = save_figure(&figure);
            break;
        case QUIT:
            figure_free(&figure);
            break;
        default:
            rc = ERR_EXTRA_ERROR;
    }
    return rc;
}

