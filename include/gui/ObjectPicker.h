//
// Created by mehdi on 05/03/16.
//

#ifndef LUMINOLGL_OBJECTPICKER_H
#define LUMINOLGL_OBJECTPICKER_H

#include "graphics/ShaderProgram.hpp"
#include "graphics/Mesh.h"
#include "graphics/Scene.h"
#include "view/CameraFreefly.hpp"
#include "geometry/Transformation.h"

namespace Gui
{
    enum PickerMode{
        TRANSLATION = 0,
        ROTATION = 1,
        SCALE = 2
    };

    class ObjectPicker {
    private:
        Geometry::Transformation* _targetTransformation;
        Geometry::BoundingBox* _targetBoundingBox;
        bool _picked;
        int _pickedAnchorAxis;
        float _markerScale;
        bool _longClick;

        PickerMode _mode;

        std::vector<Geometry::BoundingBox> _axisAnchors; /** Theses bounding boxes are used to grab the axis and transform */
        std::vector<std::vector<Geometry::BoundingBox>> _pickerAnchors; /** Theses bounding boxes are used to grab the axis and transform */

    public:
        ObjectPicker(float markerScale = 5);
        void pickObject(const glm::vec2 & cursorPosition, const glm::vec2 & cursorSpeed, Graphics::Scene& scene, const View::CameraFreefly& camera, bool click);
        void transformPickedObject(const glm::vec2 & cursorSpeed, int axis, const glm::mat4& MVP);
        void translatePickedObject(const glm::vec2 & cursorSpeed, int axis, const glm::mat4& MVP);
        void scalePickedObject(const glm::vec2 & cursorSpeed, int axis, const glm::mat4& MVP);
        void rotatePickedObject(const glm::vec2 & cursorSpeed, int axis, const glm::mat4& MVP);
        void drawPickedObject(Graphics::ShaderProgram& program);
        void switchMode(PickerMode mode);

    };
}




#endif //LUMINOLGL_OBJECTPICKER_H