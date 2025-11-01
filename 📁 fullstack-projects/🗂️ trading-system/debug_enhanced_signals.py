# debug_enhanced_signals.py
from forex_signals import EnhancedForexSignals

def debug_signals_class():
    signals_gen = EnhancedForexSignals()
    
    print("=== ENHANCEDFOREXSIGNALS DEBUG ===")
    print(f"Class: {signals_gen.__class__}")
    
    print("\n🔍 METHODS:")
    methods = [m for m in dir(signals_gen) if not m.startswith('_') and callable(getattr(signals_gen, m))]
    for method in methods:
        print(f"  - {method}")
    
    print("\n🔍 ATTRIBUTES:")
    attributes = [a for a in dir(signals_gen) if not a.startswith('_') and not callable(getattr(signals_gen, a))]
    for attr in attributes:
        try:
            value = getattr(signals_gen, attr)
            print(f"  - {attr}: {type(value)}")
        except:
            print(f"  - {attr}: <error>")
    
    print("\n🔍 TESTING COMMON METHODS:")
    common_methods = ['generate_signals', 'get_signals', 'analyze_markets', 'get_market_data']
    for method in common_methods:
        if hasattr(signals_gen, method):
            print(f"✅ {method} exists")
            try:
                result = getattr(signals_gen, method)()
                print(f"   Returns: {type(result)}")
                if result and len(result) > 0:
                    sample_key = list(result.keys())[0]
                    print(f"   Sample data: {list(result.keys())[:3]}...")
            except Exception as e:
                print(f"   Error: {e}")
        else:
            print(f"❌ {method} missing")

if __name__ == "__main__":
    debug_signals_class()