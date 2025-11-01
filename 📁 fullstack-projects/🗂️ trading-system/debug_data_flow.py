# debug_data_flow.py
import requests
import json
from forex_signals import EnhancedForexSignals

def debug_data_flow():
    print("=== DEBUGGING DATA FLOW ===")
    
    # Test signals generator directly
    print("\n1. Testing EnhancedForexSignals directly:")
    signals_gen = EnhancedForexSignals()
    market_data = signals_gen.generate_signals()
    print(f"   Raw signals: {len(market_data)} symbols")
    
    if market_data:
        sample_symbol = list(market_data.keys())[0]
        sample_data = market_data[sample_symbol]
        print(f"   Sample data for {sample_symbol}:")
        for key, value in sample_data.items():
            print(f"     {key}: {value}")
    
    # Test API endpoint
    print("\n2. Testing API endpoint:")
    try:
        response = requests.get('http://localhost:5000/api/update-all')
        data = response.json()
        print(f"   API Status: {response.status_code}")
        print(f"   Market data keys: {list(data.keys())}")
        
        if 'market_data' in data:
            print(f"   Market data entries: {len(data['market_data'])}")
            if data['market_data']:
                sample_key = list(data['market_data'].keys())[0]
                print(f"   Sample market data structure:")
                for key, value in list(data['market_data'][sample_key].items())[:5]:
                    print(f"     {key}: {value}")
        
        if 'market_regime' in data:
            print(f"   Market regime: {data['market_regime']}")
            
    except Exception as e:
        print(f"   API Error: {e}")

if __name__ == "__main__":
    debug_data_flow()