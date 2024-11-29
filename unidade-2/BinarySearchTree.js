import { Compare, defaultCompare } from './util/util.js';
import Node from './util/node.js';

/**
 * Classe que representa uma árvore binária de busca.
 */
export default class BinarySearchTree {
    constructor(compareFn = defaultCompare) {
        this.compareFn = compareFn;
        this.root = null;
    }

    Insert(key) {
        if (this.root == null) {
            this.root = new Node(key);
        } else {
            this.InsertNode(this.root, key);
        }
    }

    InsertNode(node, key) {
        if (this.compareFn(key, node.key) === Compare.LESS_THAN) {
            if (node.left == null) {
                node.left = new Node(key);
            } else {
                this.InsertNode(node.left, key);
            }
        } else {
            if (node.right == null) {
                node.right = new Node(key);
            } else {
                this.InsertNode(node.right, key);
            }
        }
    }
}