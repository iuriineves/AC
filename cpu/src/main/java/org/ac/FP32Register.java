package org.ac;

/**
 * Class that models a 32-bit floating point register in IEEE 754 format.
 */
public class FP32Register {

    /**
     * Size of the register
     */
    private static final int FP32_REGISTER_SIZE = 32;

    /**
     * Contents of the register
     */
    final boolean[] bits = new boolean[FP32_REGISTER_SIZE];

    public int size() {
        return this.bits.length;
    };

    private boolean bool(int integer) {
        return integer % 2 == 1;
    }

    public static int integer(boolean bool) {
        if (bool) return 1; else return 0;
    }

    private String str(boolean bool) {
        return integer(bool) + "";
    }

    /**
     * Stores the given value in IEEE 754 32-bit format.
     */
    public void set(float value) {
        if (value == 0) return;

        bits[31] = value < 0;

        int integer = (int) value;
        float decimal = value - integer;

        int exp = 127;
        while (integer >= 2) {
            integer /= 2;
            exp++;
        }

        if (value < 0) {
            while () {

            }
        }
    }

    /**
     * Returns the register contents as a float.
     */
    public float get() {
        // TODO
        float todo = 0;
        return todo;
    }

    /**
     * Returns a string in the format \texttt{<S> | <exp> | <mant>}, where exponent and mantissa are grouped in blocks
     * of 4 bits separated by spaces.
     */
    @Override
    public String toString() {
        // TODO
        return "TODO";
    }
}
