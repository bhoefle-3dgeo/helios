#pragma once

#include <LightKDTreeNode.h>
#include <KDTreeNode.h>
#include <KDTreeNodeRoot.h>

#include <vector>

using std::vector;

/**
 * @author Alberto M. Esmoris Pena
 * @version 1.0
 *
 * @brief Class that must be extended by any class which provides factory
 *  methods for k-dimensional trees. Notice all KDTrees should be instantiated
 *  through corresponding factories.
 *
 * @see KDTreeNodeRoot
 */
class KDTreeFactory{
private:
    // ***  SERIALIZATION  *** //
    // *********************** //
    friend class boost::serialization::access;
    /**
     * @brief Serialize a KDTree factory to a stream of bytes
     * @tparam Archive Type of rendering
     * @param ar Specific rendering for the stream of bytes
     * @param version Version number for the K dimensional tree factory
     */
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar &buildLightNodes;
    }

protected:
    // ***  ATTRIBUTES  *** //
    // ******************** //
    /**
     * @brief When it is true, the KDTreeFactory is expected to build light
     *  nodes. It is, built KDTree must have a KDTreeRootNode which children
     *  are all LightKDTreeNode. When it is false, KDTreeFactory is allowed
     *  to build KDTree with KDTreeNode children, which might require more
     *  memory
     * @see KDTreeFactory::lighten
     */
    bool buildLightNodes = true;

public:
    // ***  CONSTRUCTION / DESTRUCTION  *** //
    // ************************************ //
    /**
     * @brief K dimensional tree factory default constructor
     */
    KDTreeFactory() : buildLightNodes(true) {}
    virtual ~KDTreeFactory() = default;

    // ***  K-DIMENSIONAL TREE FACTORY METHODS  *** //
    // **********************+********************* //
    /**
     * @brief Build a KDTree from given primitives
     * @param primitives Primitives to build KDTree splitting them
     * @return Pointer to root node of built KDTree
     */
    virtual KDTreeNodeRoot * makeFromPrimitivesUnsafe(
        vector<Primitive *> &primitives
    ) = 0;
    /**
     * @brief Safe wrapper from makeFromPrimitivesUnsafe which handles a copy
     *  to make from primitives by default. This function behavior might be
     *  overridden by any derived/child class. It is expected that any
     *  implementation of makeFromPrimitives provides a way to implement
     *  the makeFromPrimitivesUnsafe method without modifying vector of input
     *  primitives. Notice this does not mean primitives themselves cannot be
     *  modified, that depends on the type of KDTreeFactory. It only means
     *  that the vector itself will not be modified, for instance due to
     *  sorting purposes.
     * @see KDTreeFactory::makeFromPrimitivesUnsafe
     */
    virtual KDTreeNodeRoot * makeFromPrimitives(
        vector<Primitive *> const &primitives
    )
    {
        vector<Primitive *> _primitives = primitives; // Copy to work over
        return makeFromPrimitivesUnsafe(_primitives);
    };

    // ***  GETTERs and SETTERs  *** //
    // ***************************** //
    /**
     * @brief Check if KDTreeFactory is building light nodes
     * @return True if KDTreeFactory is building light nodes, false otherwise
     * @see KDTreeFactory::buildLightNodes
     */
    virtual inline bool isBuildingLightNodes() {return buildLightNodes;}
    /**
     * @brief Set KDTreeFactory so it build light nodes (true) or not (false)
     * @param buildLightNodes True to build light nodes, false to don't
     * @see KDTreeFactory::buildLightNodes
     */
    virtual inline void setBuildingLightNodes(bool const buildLightNodes)
    {this->buildLightNodes = buildLightNodes;}

protected:
    // ***  LIGHTEN  *** //
    // ***************** //
    /**
     * @brief Rebuild all children of given root KDTree node as LightKDTeeeNode
     *  nodes
     * @param root KDTreeRootNode which children must be lighten
     * @see KDTreeFactory::buildLightNodes
     * @see LightKDTreeNode
     * @see KDTreeNode
     * @see KDTreeRootNode
     */
    void lighten(KDTreeNodeRoot *root);
    /**
     * @brief Assist KDTreeFactory::lighten function by handling the lighten
     *  of a given non-root node
     * @param node Node to be lighten
     * @return Light version of given node
     * @see KDTreeFactory::lighten
     */
    LightKDTreeNode * _lighten(KDTreeNode *node);
};